using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Move
    {
        private Place source;
        private Place destination;

        public Move(Place source, Place destination)
        {
            this.source = source;
            this.destination = destination;
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
            return String.Format("{0} -> {1}",
                source,
                destination);
        }
    }
}
