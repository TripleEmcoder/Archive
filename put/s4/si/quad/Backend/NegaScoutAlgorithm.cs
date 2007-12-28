using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class NegaScoutAlgorithm : Algorithm
    {
        private static int inf = int.MaxValue - 10;

        private TranspositionTable transTable;

        public NegaScoutAlgorithm()
        {
            transTable = new TranspositionTable();
        }

        public override string Name
        {
            get { return "NegaScout"; }
        }

        private int start;

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            hits = 0;
            start = depth;

            for (int i = 1; i < depth; ++i)
                Run(evaluator, board, player, i, -inf, inf);

            return Run(evaluator, board, player, depth, -inf, inf);
        }

        private Result Run(Evaluator evaluator, Board board, Player player, int depth, int alpha, int beta)
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

            if (depth == start)
                total = possibleMoves.Count;

            if (transposition != null)
            {
                int index = possibleMoves.IndexOf(transposition.BestMove.Move);
                if (index == -1)
                    throw new Exception(String.Format("Move \"{0}\" not found.", transposition.BestMove.Move));
                possibleMoves[index] = possibleMoves[0];
                possibleMoves[0] = transposition.BestMove.Move;
            }

            Transition transition = board.PerformMove(possibleMoves[0]);

            Result best = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1, -beta, -alpha);
            best = new Result(possibleMoves[0], -best.Value);

            board.ReverseTransition(transition);

            if (depth == start)
                done = 1;

            if (best.Value < beta)
            {
                foreach (Move move in possibleMoves.GetRange(1, possibleMoves.Count - 1))
                {
                    if (best.Value > alpha)
                        alpha = best.Value;

                    transition = board.PerformMove(move);

                    Result candidate = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1, -alpha - 1, -alpha);
                    candidate = new Result(move, -candidate.Value);

                    board.ReverseTransition(transition);

                    if (candidate.Value >= beta)
                    {
                        best = candidate;
                        break;
                    }

                    if (candidate.Value > alpha)
                    {
                        transition = board.PerformMove(move);

                        best = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1, -beta, -candidate.Value);
                        best = new Result(move, -best.Value);

                        board.ReverseTransition(transition);
                    }
                    else if (candidate.Value > best.Value)
                    {
                        best = candidate;
                    }

                    if (depth == start)
                        done++;
                }
            }

            transTable.Save(board, best, prevalpha, beta, depth);

            return best;
        }
    }
}
