using System;

namespace PP.DB.Inf75922.Model
{
    public class LibraryException : Exception
    {        
        public LibraryException()
        {
        }

        public LibraryException(string message)
            : base(message)
        {
        }

        public LibraryException(string message, Exception innerException)
            : base(message, innerException)
        {
        }

    }
}