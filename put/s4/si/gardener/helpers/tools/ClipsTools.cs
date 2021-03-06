using System;
using System.Collections.Generic;
using System.Text;

public static class ClipsTools
{
    public static string MakeIdentifier(string value)
    {
        string result = value.ToLower();

        result = result.Replace(' ', ' ');
        result = result.Replace('ą', 'a');
        result = result.Replace('ć', 'c');
        result = result.Replace('ę', 'e');
        result = result.Replace('ł', 'l');
        result = result.Replace('ń', 'n');
        result = result.Replace('ó', 'o');
        result = result.Replace('ś', 's');
        result = result.Replace('ź', 'z');
        result = result.Replace('ż', 'z');

        result = result.Replace(' ', '_');
        result = result.Replace("\'", "");

        return result;
    }
}
