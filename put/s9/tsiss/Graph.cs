using System;
using Fluent.IO;
using QuickGraph;

namespace FactFinder
{
    public class Vertex
    {
    }

    public class EntityVertex : Vertex
    {
        public Uri Uri { get; private set; }
        public string Name { get; private set; }
        public Path Photo { get; private set; }

        public EntityVertex(Uri uri, string name, Path photo)
        {
            Uri = uri;
            Name = name;
            Photo = photo;
        }

        public override string ToString()
        {
            return Uri.AbsoluteUri;
        }
    }

    public class LiteralVertex : Vertex
    {
        public string Literal { get; private set; }

        public LiteralVertex(string literal)
        {
            Literal = literal;
        }

        public override string ToString()
        {
            return Literal;
        }
    }

    public class Edge : TaggedEdge<Vertex, Uri>
    {
        public Edge(Vertex source, Vertex target, Uri tag) 
            : base(source, target, tag)
        {
        }
    }
}