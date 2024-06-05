/*we have to return the next binary representation of string and soo doing that
we first remove the starting zeroes then we come with the solution of if there is '0' then
we will do it one and return it else if there is one then we have to take it as '0'
and at the end we have to return the 1+remaining string */

{

    int k = -1;
    int flag = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '0')
        {
            k = i;
            flag++;
        }
        else
            break;
    }

    if (flag != 0)
        s.erase(0, k + 1);

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            return s;
        }
        else
        {
            s[i] = '0';
        }
    }

    s = "1" + s;
    return s;
}