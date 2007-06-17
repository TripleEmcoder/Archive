using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class NegMaxAlgorithm : Algorithm
    {
        public override Result Run(Player player, Board board, int depth)
        {
            if (depth == 0)
                return new Result(null, board.GetValue(Player.White));

            Result winner = new Result(null, int.MinValue);

            foreach (Move move in board.GetPossibleMoves(player))
            {
                Transition transition = board.PerformMove(move);

                Result candidate = Run(Helper.SwapPlayer(player), board, depth - 1);

                if (-candidate.Value > winner.Value)
                    winner = new Result(move, -candidate.Value);

                board.ReverseTransition(transition);
            }

            return winner;
        }
    }
}
