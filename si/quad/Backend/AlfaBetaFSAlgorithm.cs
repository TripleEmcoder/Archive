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

        private int start;

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            hits = 0;
            start = depth;

            return Run(evaluator, board, player, depth, -inf, inf);
        }

        private Result Run(Evaluator evaluator, Board board, Player player, int depth, int alpha, int beta)
        {
            hits++;

            if (depth == 0 || board.Winner != Player.None)
                return new Result(null, evaluator.Run(board, player));

            Result best = new Result(null, -inf);

            List<Move> moves = board.GetPossibleMovesSorted(player);

            if (depth == start)
                total = moves.Count;

            foreach (Move move in moves)
            {
                Transition transition = board.PerformMove(move);
                Result candidate = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1, -beta, -alpha);

                board.ReverseTransition(transition);

                if (-candidate.Value > best.Value)
                    best = new Result(move, -candidate.Value);

                if (best.Value >= beta)
                    break;

                if (best.Value > alpha)
                    alpha = best.Value;

                if (depth == start)
                    done++;
            }

            return best;
        }
    }
}
