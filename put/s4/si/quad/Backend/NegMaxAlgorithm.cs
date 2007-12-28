using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class NegMaxAlgorithm : Algorithm
    {
        public override string Name
        {
            get { return "NegMax"; }
        }

        private int start;

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            hits = 0;
            start = depth;

            return RunInternal(evaluator, board, player, depth);
        }

        private Result RunInternal(Evaluator evaluator, Board board, Player player, int depth)
        {
            hits++;

            if (depth == 0 || board.Winner != Player.None)
                return new Result(null, evaluator.Run(board, player));

            Result winner = new Result(null, int.MinValue);

            List<Move> moves = board.GetPossibleMovesSorted(player);

            if (depth == start)
                total = moves.Count;

            foreach (Move move in moves)
            {
                Transition transition = board.PerformMove(move);

                Result candidate = RunInternal(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1);

                if (-candidate.Value > winner.Value)
                    winner = new Result(move, -candidate.Value);

                board.ReverseTransition(transition);

                if (depth == start)
                    done++;
            }

            return winner;
        }
    }
}
