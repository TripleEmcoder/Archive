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

            foreach (Place place in BackendHelper.GetAllPlaces(board.Dimension))
            {
               result += bonus[MatchLine(board, player, place, new Place(0, 1))];
               result += bonus[MatchLine(board, player, place, new Place(1, 0))];
               
               result -= bonus[MatchLine(board, enemy, place, new Place(0, 1))];
               result -= bonus[MatchLine(board, enemy, place, new Place(1, 0))];

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
            if (!BackendHelper.IsPlaceValid(place + 3 * vector, board.Dimension))
                return 4;
            
            Player enemy = BackendHelper.SwapPlayer(player);

            int result = 4;

            for (int i = 0; i < 4; ++i)
            {
                Player current = board.GetPlayer(place + i * vector);

                if (current == enemy)
                    return 4;
                else if (current == player)
                    result--;
            }

            return result;
        }
    }

}
