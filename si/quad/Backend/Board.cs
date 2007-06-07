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
        }

        public int Dimension
        {
            get { return dimension; }
        }

        public List<Move> GetPossibleMoves(Player player)
        {
            List<Move> moves = new List<Move>();

            if (befores[player] > 0)
            {
                //faza I - dostawianie
                foreach (Point destination in Helper.GetAllPoints(dimension))
                    if (this[destination] == Player.None)
                        moves.Add(new Move(null, destination));
            }
            else
            {
                //faza II - przesuwanie

                Point[] vectors = {
                    new Point( 0,  1), //polnoc
                    new Point( 0, -1), //poludnie
                    new Point( 1,  0), //wschod
                    new Point(-1,  0), //zachod
                };

                foreach (Point source in Helper.GetAllPoints(dimension))
                    if (this[source] == player)
                        foreach (Point vector in vectors)
                        {
                            Point destination = source + vector;
                            
                            if (Helper.IsPointValid(destination, dimension))
                                if (this[destination] == Player.None)
                                    moves.Add(new Move(source, destination));
                        }
            }

            return moves;
        }

        public Player this[int column, int row]
        {
            get { return fields[column, row]; }
        }

        private Player this[Point point]
        {
            get { return fields[point.Column, point.Row]; }
            set { fields[point.Column, point.Row] = value; }
        }

        public Transition PerformMove(Player player, Move move)
        {
            Transition transition = new Transition();

            transition.Moves.Add(move);

            if (move.Source == null)
            {
                befores[player]--;
                this[move.Destination] = player;
            }
            else if (move.Destination == null)
            {
                afters[this[move.Source]]++;
                this[move.Source] = Player.None;
            }
            else
            {
                this[move.Destination] = this[move.Source];
                this[move.Source] = Player.None;
            }

            return transition;
        }

        public void ReverseTransition(Player player, Transition transition)
        {
            throw new System.NotImplementedException();
        }
    }
}
