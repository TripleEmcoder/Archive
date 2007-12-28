using System;
using System.Collections.Generic;
using System.Text;

namespace Types
{
    public struct Complex
    {
        private double real;
        private double imaginary;
        
        public Complex(double real, double imaginary)
        {
            this.real = real;
            this.imaginary = imaginary;
        }

        public double Real
        {
            get { return real; }
            set { real = value; }
        }

        public double Imaginary
        {
            get { return imaginary; }
            set { imaginary = value; }
        }

        public double Modulus
        {
            get { return Math.Sqrt(real * real + imaginary * imaginary); }
        }

        public double Argument
        {
            get { return Math.Atan2(imaginary, real); }
        }

        public static Complex operator +(Complex c1, Complex c2)
        {
            return new Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
        }

        public override string ToString()
        {
            return string.Format("{0} + {1}i", real, imaginary);
        }
    }

}
