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
                    
                    //foreach (Place vector2 in BackendHelper.Vectors.Values)
                    //{
                    //    Place place2 = place1 + vector2;

                    //    if (!BackendHelper.IsPlaceValid(place2, dimension))
                    //        continue;

                    //    Player friend = GetPlayer(place2);

                    //    //pionek musi istnieć i nie być przeciwnikiem
                    //    if (friend == Player.None || friend != move.Player)
                    //        continue;

                    //    //potrzeba dwóch różnych pionków do zbicia
                    //    if (place2.Equals(move.Destination))
                    //        continue;

                    //    Move capture = new Move(enemy, place1, null);
                    //    PerformAtomicMove(capture);
                    //    transition.Moves.Add(capture);

                    //    break;
                    //}
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
    }
}
