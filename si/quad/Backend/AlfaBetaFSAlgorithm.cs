using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class AlfaBetaFSAlgorithm : Algorithm
    {
        private static int inf = int.MaxValue - 10;
        
        public override string Name
        {
            get { return "AlfaBetaFS"; }
        }

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            return Run(evaluator, board, player, depth, -inf, inf);
        }

        public Result Run(Evaluator evaluator, Board board, Player player, int depth, int alpha, int beta)
        {
            hits++;

            if (depth == 0 || board.Winner != Player.None)
                return new Result(null, evaluator.Run(board, player));

            Result best = new Result(null, -inf);

            foreach (Move move in board.GetPossibleMovesSorted(player))
            {
                Transition transition = board.PerformMove(move);

                if (depth == 3 && move.Destination.ToString() == "B4")
                {
                    ;
                }


                Result candidate = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1, -beta, -alpha);

                board.ReverseTransition(transition);

                if (-candidate.Value > best.Value)
                    best = new Result(move, -candidate.Value);

                if (best.Value >= beta)
                    break;

                if (best.Value > alpha)
                    alpha = best.Value;
            }

            return best;
        }
    }
}
