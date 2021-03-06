using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Board
    {
        private static int maxBoardSize = 8;
        private static int[, ,] hashValues;

        static Board()
        {
            hashValues = new int[maxBoardSize, maxBoardSize, 3];
            Random rand = new Random();
            foreach (Place place in BackendHelper.GetAllPlaces(maxBoardSize))
            {
                hashValues[place.Column, place.Row, (int)Player.None] = 0;
                hashValues[place.Column, place.Row, (int)Player.White] = rand.Next();
                hashValues[place.Column, place.Row, (int)Player.Black] = rand.Next();
            }
        }

        private int dimension;
        private Player[,] fields;
        private Dictionary<Player, int> befores;
        private Dictionary<Player, int> afters;
 
        public Board(int dimension, int count)
        {
            if (dimension > maxBoardSize)
                throw new ArgumentException("dimension > maxBoardSize");

            this.dimension = dimension;
            fields = new Player[dimension, dimension];

            befores = new Dictionary<Player, int>();
            befores[Player.White] = count;
            befores[Player.Black] = count;

            afters = new Dictionary<Player, int>();
            afters[Player.White] = 0;
            afters[Player.Black] = 0;
        }

        public int Dimension
        {
            get { return dimension; }
        }

        public Dictionary<Player, int> Befores
        {
            get { return befores; }
        }

        public Player GetPlayer(Place place)
        {
            return fields[place.Column, place.Row];
        }

        private void SetPlayer(Place place, Player value)
        {
            fields[place.Column, place.Row] = value;
        }

        public List<Move> GetPossibleMoves(Player player)
        {
            List<Move> moves = new List<Move>();

            if (befores[player] > 0)
            {
                //faza I - dostawianie

                foreach (Place destination in BackendHelper.GetAllPlaces(dimension))
                    if (GetPlayer(destination) == Player.None)
                        moves.Add(new Move(player, null, destination));
            }
            else
            {
                //faza II - przesuwanie

                foreach (Place source in BackendHelper.GetAllPlaces(dimension))
                    if (GetPlayer(source) == player)
                        foreach (Place vector in BackendHelper.Vectors.Values)
                        {
                            Place destination = source + vector;

                            if (BackendHelper.IsPlaceValid(destination, dimension))
                                if (GetPlayer(destination) == Player.None)
                                    moves.Add(new Move(player, source, destination));
                        }
            }

            return moves;
        }

        public List<Move> GetPossibleMovesSorted(Player player)
        {
            List<Move> moves = GetPossibleMoves(player);

            Random rand = new Random();

            for (int i = 0; i < moves.Count; ++i)
            {
                int k = rand.Next(moves.Count);

                Move temp = moves[i];
                moves[i] = moves[k];
                moves[k] = temp;
            }
                                
            moves.Sort(new BackendHelper.MoveDestinationCenterComparer(dimension));

            return moves;
        }

        public Transition PerformMove(Move move)
        {
            Transition transition = new Transition();

            PerformAtomicMove(move);
            transition.Moves.Add(move);

            if (move.Source != null)
            {
                //faza II - zbijanie

                foreach (Place vector1 in BackendHelper.Vectors.Values)
                {
                    Place place1 = move.Destination + vector1;

                    if (!BackendHelper.IsPlaceValid(place1, dimension))
                        continue;

                    Player enemy = GetPlayer(place1);

                    //sąsiad musi istnieć i być przeciwnikiem
                    if (enemy == Player.None || enemy == move.Player)
                        continue;

                    Place place2 = place1 + vector1;

                    if (!BackendHelper.IsPlaceValid(place2, dimension))
                        continue;

                    Player friend = GetPlayer(place2);

                    //pionek musi istnieć i nie być przeciwnikiem
                    if (friend == Player.None || friend != move.Player)
                        continue;

                    Move capture = new Move(enemy, place1, null);
                    PerformAtomicMove(capture);
                    transition.Moves.Add(capture);
                    
                }
            }

            return transition;
        }

        public void ReverseTransition(Transition transition)
        {
            transition.Moves.Reverse();

            foreach (Move move in transition.Moves)
                ReverseAtomicMove(move);
        }

        private void PerformAtomicMove(Move move)
        {
            if (move.Source == null)
            {
                befores[move.Player]--;
                SetPlayer(move.Destination, move.Player);
            }
            else if (move.Destination == null)
            {
                if (move.Player != GetPlayer(move.Source))
                    throw new ArgumentException();

                afters[move.Player]++;
                SetPlayer(move.Source, Player.None);
            }
            else
            {
                if (move.Player != GetPlayer(move.Source))
                    throw new ArgumentException();

                SetPlayer(move.Source, Player.None);
                SetPlayer(move.Destination, move.Player);
            }
        }

        private void ReverseAtomicMove(Move move)
        {
            if (move.Destination == null)
            {
                afters[move.Player]--;
                SetPlayer(move.Source, move.Player);
            }
            else if (move.Source == null)
            {
                if (move.Player != GetPlayer(move.Destination))
                    throw new ArgumentException();

                befores[move.Player]++;
                SetPlayer(move.Destination, Player.None);
            }
            else
            {
                if (move.Player != GetPlayer(move.Destination))
                    throw new ArgumentException();

                SetPlayer(move.Source, move.Player);
                SetPlayer(move.Destination, Player.None);
            }
        }

        public Player Winner
        {
            get
            {
                foreach (Place place1 in BackendHelper.GetAllPlaces(dimension))
                {
                    Player player1 = GetPlayer(place1);

                    if (player1 == Player.None)
                        continue;

                    foreach (Place vector in BackendHelper.Vectors.Values)
                    {
                        Place place2 = place1 + vector;

                        int count = 1;

                        while (BackendHelper.IsPlaceValid(place2, dimension)
                            && GetPlayer(place2) == player1)
                        {
                            if (++count == 4)
                                return player1;

                            place2 = place2 + vector;
                        }
                    }
                }

                return Player.None;
            }
        }

        public override bool Equals(object other)
        {
            Board board = other as Board;

            if (board == null)
                return base.Equals(other);

            if (dimension != board.dimension)
                return false;

            foreach (Place place in BackendHelper.GetAllPlaces(dimension))
                if (GetPlayer(place) != board.GetPlayer(place))
                    return false;

            return true;
        }

        public override int GetHashCode()
        {
            int result = 0;
            foreach (Place place in BackendHelper.GetAllPlaces(dimension))
                result ^= hashValues[place.Column, place.Row, (int)GetPlayer(place)];
            return result;
        }

        public override string ToString()
        {
            string result = "";

            foreach (Place place in BackendHelper.GetAllPlaces(dimension))
            {
                switch (GetPlayer(place))
                {
                    case Player.None:
                        result += ' ';
                        break;
                    case Player.Black:
                        result += 'B';
                        break;
                    case Player.White:
                        result += 'W';
                        break;
                }
            }

            return result;
        }
    }
}
