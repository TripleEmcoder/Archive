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

        public override Result Run(Evaluator evaluator, Board board, Player player, int depth)
        {
            hits++;

            if (depth == 0 || board.Winner != Player.None)
                return new Result(null, evaluator.Run(board, player));

            Result winner = new Result(null, int.MinValue);

            foreach (Move move in board.GetPossibleMoves(player))
            {
                Transition transition = board.PerformMove(move);

                Result candidate = Run(evaluator, board, BackendHelper.SwapPlayer(player), depth - 1);

                if (-candidate.Value > winner.Value)
                    winner = new Result(move, -candidate.Value);

                board.ReverseTransition(transition);
            }

            return winner;
        }
    }
}
