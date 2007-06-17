using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Board
    {
        private int dimension;
        private Player[,] fields;
        private Dictionary<Player, int> befores;
        private Dictionary<Player, int> afters;
        private Dictionary<Direction, Place> vectors;

        public Board(int dimension, int count)
        {
            this.dimension = dimension;
            fields = new Player[dimension, dimension];

            befores = new Dictionary<Player, int>();
            befores[Player.White] = count;
            befores[Player.Black] = count;

            afters = new Dictionary<Player, int>();
            afters[Player.White] = 0;
            afters[Player.Black] = 0;

            vectors = new Dictionary<Direction, Place>();
            vectors[Direction.North] = new Place(0, 1);
            vectors[Direction.South] = new Place(0, -1);
            vectors[Direction.East] = new Place(1, 0);
            vectors[Direction.West] = new Place(-1, 0);
        }

        public int Dimension
        {
            get { return dimension; }
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

                foreach (Place destination in Helper.GetAllPlaces(dimension))
                    if (GetPlayer(destination) == Player.None)
                        moves.Add(new Move(null, destination));
            }
            else
            {
                //faza II - przesuwanie

                foreach (Place source in Helper.GetAllPlaces(dimension))
                    if (GetPlayer(source) == player)
                        foreach (Place vector in vectors.Values)
                        {
                            Place destination = source + vector;

                            if (Helper.IsPlaceValid(destination, dimension))
                                if (GetPlayer(destination) == Player.None)
                                    moves.Add(new Move(source, destination));
                        }
            }

            return moves;
        }

        public Transition PerformMove(Player player, Move move)
        {
            Transition transition = new Transition();

            PerformAtomicMove(player, move);
            transition.Moves.Add(move);

            if (move.Source != null)
            {
                //faza II - zbijanie

                foreach (Place vector1 in vectors.Values)
                {
                    Place enemy = move.Destination + vector1;

                    if (!Helper.IsPlaceValid(enemy, dimension))
                        continue;

                    //sąsiad musi istnieć
                    if (GetPlayer(enemy) == Player.None)
                        continue;
                    
                    //sąsiad musi być przeciwnikiem
                    if (GetPlayer(enemy) == player)
                        continue;

                    foreach (Place vector2 in vectors.Values)
                    {
                        Place friend = enemy + vector2;

                        if (!Helper.IsPlaceValid(friend, dimension))
                            continue;

                        //pionek musi istnieć
                        if (GetPlayer(friend) == Player.None)
                            continue;

                        //pionek przeciwnika się nie liczy
                        if (GetPlayer(friend) != player)
                            continue;

                        //potrzeba dwóch pionków do zbicia
                        if (friend.Equals(move.Destination))
                            continue;

                        Move capture = new Move(enemy, null);
                        PerformAtomicMove(Player.None, capture);
                        transition.Moves.Add(capture);

                        break;
                    }
                }
            }

            return transition;
        }

        private void PerformAtomicMove(Player player, Move move)
        {
            if (move.Source == null)
            {
                befores[player]--;
                SetPlayer(move.Destination, player);
            }
            else if (move.Destination == null)
            {
                afters[GetPlayer(move.Source)]++;
                SetPlayer(move.Source, Player.None);
            }
            else
            {
                SetPlayer(move.Destination, GetPlayer(move.Source));
                SetPlayer(move.Source, Player.None);
            }
        }

        public void ReverseTransition(Player player, Transition transition)
        {
            throw new System.NotImplementedException();
        }

        public int GetValue(Player player)
        {
            return 0;
        }
    }
}
