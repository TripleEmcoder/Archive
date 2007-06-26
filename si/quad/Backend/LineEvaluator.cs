using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class LineEvaluator : Evaluator
    {
        public override string Name
        {
            get { return "Line"; }
        }

        public override int Run(Board board, Player player)
        {
            int result = 0;

            foreach (Place place1 in BackendHelper.GetAllPlaces(board.Dimension))
            {
                int k;
                Player currentPlayer;
                if (player == board.GetPlayer(place1))
                {
                    currentPlayer = player;
                    k = 1;
                }
                else if (BackendHelper.SwapPlayer(player) == board.GetPlayer(place1))
                {
                    currentPlayer = BackendHelper.SwapPlayer(player);
                    k = -1;
                }
                else
                    continue;

                foreach (Place vector in BackendHelper.Vectors.Values)
                {
                    Place place2 = place1 + vector;

                    result += k;

                    while (BackendHelper.IsPlaceValid(place2, board.Dimension)
                        && board.GetPlayer(place2) == currentPlayer)
                    {
                        result += k;
                        place2 = place2 + vector;
                    }
                }
            }

            return result;
        }
    }
}
