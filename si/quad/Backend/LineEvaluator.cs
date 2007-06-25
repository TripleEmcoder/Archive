using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class LineEvaluator : Evaluator
    {
        public override int Run(Board board, Player player)
        {
            int result = 0;

            foreach (Place place1 in Helper.GetAllPlaces(board.Dimension))
            {
                if (player == board.GetPlayer(place1))
                {
                    foreach (Place vector in Helper.Vectors.Values)
                    {
                        Place place2 = place1 + vector;

                        result++;

                        while (Helper.IsPlaceValid(place2, board.Dimension)
                            && board.GetPlayer(place2) == player)
                        {
                            result++;
                            place2 = place2 + vector;
                        }
                    }
                }
            }

            return result;
        }
    }
}
