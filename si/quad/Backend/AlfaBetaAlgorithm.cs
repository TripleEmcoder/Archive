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

        private int start;

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            hits = 0;
            start = depth;

            return Run(evaluator, board, player, depth, new Result(null, -inf), new Result(null, inf));
        }

        private Result Run(Evaluator evaluator, Board board, Player player, int depth, Result alpha, Result beta)
        {
            hits++;

            if (depth == 0 || board.Winner != Player.None)
                return new Result(null, evaluator.Run(board, player));

            List<Move> moves = board.GetPossibleMovesSorted(player);

            if (depth == start)
                total = moves.Count;

            foreach (Move move in moves)
            {
                Transition transition = board.PerformMove(move);

                Result candidate = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1,
                    new Result(beta.Move, -beta.Value), new Result(alpha.Move, -alpha.Value));

                board.ReverseTransition(transition);

                if (-candidate.Value > alpha.Value)
                    alpha = new Result(move, -candidate.Value);

                if (alpha.Value >= beta.Value)
                    return beta;

                if (depth == start)
                    done++;
            }

            return alpha;
        }

    }
}
