using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class TestEvaluator : Evaluator
    {
        private static int[] bonus = { 100, 10, 1, 0, 0 };

        public override string Name
        {
            get { return "Test"; }
        }

        public override int Run(Board board, Player player)
        {
            Player enemy = BackendHelper.SwapPlayer(player);

            int result = 0;

            for (int i = 0; i < board.Dimension; ++i)
            {
                result += MatchLine(board, player, new Place(i, 0), new Place(0, 1));
                result += MatchLine(board, player, new Place(0, i), new Place(1, 0));
            }

            for (int i = 0; i < 4; ++i)
            {
                Player current = board.GetPlayer(new Place(board.Dimension / 2 - i % 2, board.Dimension / 2 - i / 2));
                if (current == player)
                    result++;
                else if (current == enemy)
                    result--;
            }
            
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
                        k = -1;
                    else
                        k = 0;

                    result += k * bonus[places[Player.None]];
                }

                place1 += vector;
            }

            return result;
        }
    }

}
