using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class AlfaBetaAlgorithm : Algorithm
    {
        private static int inf = int.MaxValue-10;

        public override string Name
        {
            get { return "AlfaBeta"; }
        }

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            return Run(evaluator, board, player, depth, new Result(null, -inf), new Result(null, inf));
        }

        public Result Run(Evaluator evaluator, Board board, Player player, int depth, Result alpha, Result beta)
        {
            hits++;

            if (depth == 0 || board.Winner != Player.None)
                return new Result(null, evaluator.Run(board, player));

            foreach (Move move in board.GetPossibleMoves(player))
            {
                Transition transition = board.PerformMove(move);

                Result candidate = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1,
                    new Result(beta.Move, -beta.Value), new Result(alpha.Move, -alpha.Value));

                board.ReverseTransition(transition);

                if (-candidate.Value > alpha.Value)
                    alpha = new Result(move, -candidate.Value);

                if (alpha.Value >= beta.Value)
                    return beta;
            }

            return alpha;
        }

    }
}
