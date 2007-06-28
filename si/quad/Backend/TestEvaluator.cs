using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class TestEvaluator : Evaluator
    {
        private static int inf = 1000;
        private static int[] lineBonus = { 100, 50, 10, 0, 0 };
        private static int[] distanceBonus = { 1, 1, 0, 0 }; 

        public override string Name
        {
            get { return "Test"; }
        }

        public override int Run(Board board, Player player)
        {
            Player enemy = BackendHelper.SwapPlayer(player);

            Player winner = board.Winner;

            if (winner == player)
                return inf;
            else if (winner == enemy)
                return -inf;

            int result = 0;

            for (int i = 0; i < board.Dimension; ++i)
            {
                result += MatchLine(board, player, new Place(i, 0), new Place(0, 1));
                result += MatchLine(board, player, new Place(0, i), new Place(1, 0));
            }

            //if (board.GetPlayer(new Place(3, 3)) == player)
            //    result++;
            //else if (board.GetPlayer(new Place(3, 3)) == enemy)
            //    result--;

            return result;
        }

        private int MatchLine(Board board, Player player, Place place, Place vector)
        {
            Dictionary<Player, int> places = new Dictionary<Player, int>();
            places[Player.None] = 0;
            places[Player.White] = 0;
            places[Player.Black] = 0;

            Player enemy = BackendHelper.SwapPlayer(player);
            Place place1 = place;

            int result = 0;
            int count = 0;

            //while (BackendHelper.IsPlaceValid(place1, board.Dimension))
            for (int i = 0; i < board.Dimension; ++i)
            {
                places[board.GetPlayer(place1)]++;
                count++;

                if (count > 4)
                {
                    places[board.GetPlayer(place1 + (-4 * vector))]--;
                    count--;
                }

                if (count == 4)
                {
                    int k;

                    if (places[enemy] == 0)
                        k = 1;
                    else if (places[player] == 0)
                        k = -2;
                    else
                        k = 0;

                    result += k * lineBonus[places[Player.None]];
                }

                place1 += vector;
            }

            return result;
        }
    }

}
