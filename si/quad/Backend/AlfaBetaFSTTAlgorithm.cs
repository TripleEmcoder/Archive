using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class AlfaBetaFSTTAlgorithm : Algorithm
    {
        private static int inf = int.MaxValue - 10;
        
        private TranspositionTable transTable;

        public AlfaBetaFSTTAlgorithm()
        {
            transTable = new TranspositionTable();
        }

        public override string Name
        {
            get { return "AlfaBetaFSTT"; }
        }

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            //for (int i = 1; i < depth; ++i)
            //    Run(evaluator, board, player, i, -inf, inf);
            return Run(evaluator, board, player, depth, -inf, inf);
        }

        public Result Run(Evaluator evaluator, Board board, Player player, int depth, int alpha, int beta)
        {
            hits++;

            if (depth == 0 || board.Winner != Player.None)
                return new Result(null, evaluator.Run(board, player));

            int prevalpha = alpha;

            Transposition transposition = transTable.Lookup(board, player);

            if (transposition != null && transposition.Depth >= depth)
            {
                switch (transposition.Bound)
                {
                    case EvaluationBound.Lower:
                        alpha = Math.Max(alpha, transposition.BestMove.Value);
                        break;
                    case EvaluationBound.Upper:
                        beta = Math.Min(beta, transposition.BestMove.Value);
                        break;
                    case EvaluationBound.Accurate:
                        alpha = beta = transposition.BestMove.Value;
                        break;
                }

                if (alpha >= beta)
                    return transposition.BestMove;
            }

            List<Move> possibleMoves = board.GetPossibleMovesSorted(player);

            if (transposition != null)
            {
                int index = possibleMoves.IndexOf(transposition.BestMove.Move);
                if (index == -1)
                    throw new Exception(String.Format("Move \"{0}\" not found.", transposition.BestMove.Move));
                possibleMoves[index] = possibleMoves[0];
                possibleMoves[0] = transposition.BestMove.Move;
            }

            Result best = new Result(null, -inf);

            foreach (Move move in possibleMoves)
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
            }

            transTable.Save(board, best, prevalpha, beta, depth);

            return best;
        }
    }
}
