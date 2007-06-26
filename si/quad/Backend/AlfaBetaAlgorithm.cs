using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class AlfaBetaAlgorithm : Algorithm
    {
        public override string Name
        {
            get { return "AlfaBeta"; }
        }

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            return Run(evaluator, board, player, depth, new Result(null, int.MinValue + 10), new Result(null, int.MaxValue - 10));
        }

        public Result Run(Evaluator evaluator, Board board, Player player, int depth, Result alpha, Result beta)
        {
            if (depth == 0)
                return new Result(null, evaluator.Run(board, player));

            //Result winner = new Result(null, int.MinValue);

            foreach (Move move in board.GetPossibleMoves(player))
            {
                Transition transition = board.PerformMove(move);

                Result candidate = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1,
                    new Result(beta.Move, -beta.Value), new Result(alpha.Move, -alpha.Value));

                if (-candidate.Value > alpha.Value)
                    alpha = new Result(move, -candidate.Value);

                board.ReverseTransition(transition);

                if (alpha.Value >= beta.Value)
                    return beta;
            }

            return alpha;
        }
    }
}
