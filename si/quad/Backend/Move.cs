using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Move
    {
        private Player player;
        private Place source;
        private Place destination;

        public Move(Player player, Place source, Place destination)
        {
            this.player = player;
            this.source = source;
            this.destination = destination;
        }

        public Player Player
        {
            get { return player; }
            set { player = value; }
        }

        public Place Source
        {
            get { return source; }
            set { source = value; }
        }

        public Place Destination
        {
            get { return destination; }
            set { destination = value; }
        }

        public override string ToString()
        {
            return String.Format("{0}: {1} -> {2}",
                player,
                source,
                destination);
        }

        public override bool Equals(object other)
        {
            Move move = other as Move;

            if (move == null)
                return base.Equals(other);

            return player == move.Player 
                && ((source == null && move.Source == null) || (source != null && source.Equals(move.Source)))
                && ((destination == null && move.Destination == null) || (destination != null && destination.Equals(move.Destination)));
        }
    }
}
