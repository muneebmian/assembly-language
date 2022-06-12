#include "Token_stream.h"

Token Token_stream::get()	 // read a Token from the Token_stream
{
    if (full)
    {
        full=false;    // check if we already have a Token ready
        return buffer;
    }

    char ch;
    cin >> ch;	// note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
        case '(':
        case ')':
        case ';':
        case 'q':
        case '+':

        case '-':
        case '*':
        case '/':
        case 'fact':
            {return Token{ch};	
             break;}	// let each character represent itself
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            cin.putback(ch);		     // put digit back into the input stream
            double val;
            cin >> val;		     // read a floating-point number
            return Token{number,val}; // rather than Token{'8',val}
            break;
        }
    case '!':
        {return Token{fact};
         break;}

    ///look for an 's'
    ///if the stream contains 's''i''n', return a sine token
    ///if the stream contains 's''q''r''t', return a root token
    ///else throw a Bad token exception (use error function)
     case 's':
    {
        cin >> ch;
        if(ch == 'i')
        {
                cin >> ch;
                if(ch == 'n')
                {
                        return Token{sine};
                }
        }
        else if(ch == 'q') {
                cin >> ch;
                if(ch == 'r')
                {
                        cin >> ch;
                        if(ch == 't')
                        {
                            return Token{root};
                        }
                }
        break;
        }
    default:
        error("Bad token");

    }
    }


}
void Token_stream::ignore(char c)
// skip characters until we find a c; also discard that c
{
    // first look in buffer:
    if (full && c==buffer.kind)  	// && means and
    {
        full = false;
        return;
    }
    full = false;	// discard the contents of buffer
    // now search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c)
            return;
}

void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer=t;
    full=true;
}
