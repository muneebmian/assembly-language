#include "Temperatures.h"
#include "std_lib_facilities.h"

string int_to_month(int i)
{
    return month_print_tbl.at(i);
}
istream& operator>>(istream& is, Reading& r)
// read a temperature reading from is into r
// format: ( 3 4 9.7 )
// check format, but don’t bother with data validity
{
    char ch1;
    if (is>>ch1 && ch1!='(')
    { // could it be a Reading?
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2!=')') error("bad reading"); // messed-up reading
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}
istream& operator>>(istream& is, Month& m) // format: { month feb . . . }
{
    char ch = 0;
    if (is >> ch && ch!='{')
    {
        is.unget();
        is.clear(ios_base::failbit); // we failed to read a Month
        return is;
    }
    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker!="month") error("bad start of month");
    m.month = month_to_int(mm);
    int duplicates = 0;
    int invalids = 0;
    for (Reading r; is >> r; )
    {
        if (is_valid(r))
        {
            if (m.days[r.day].hours[r.hour] != not_a_reading)
                ++duplicates;
            m.days[r.day].hours[r.hour] = r.temperature;
        }
        else
            ++invalids;
    }
    if (invalids) error("invalid readings in month",invalids);
    if (duplicates) error("duplicate readings in month", duplicates);
    end_of_loop(is,'}',"bad end of month");
    return is;
}


int month_to_int(string s)
// is s the name of a month? If so return its index [0:11] otherwise –1
{
    for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
    return -1;
}
bool is_valid(const Reading& r)
// a rough test
{
    if (r.day<1 || 31<r.day) return false;
    if (r.hour<0 || 23<r.hour) return false;
    if (r.temperature<implausible_min|| implausible_max<r.temperature)
    return false;
    return true;
}
void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail())
    { // use term as terminator and/or separator
        ist.clear();
        char ch;
        if (ist>>ch && ch==term) return; // all is fine
        error(message);
    }
}
istream& operator>>(istream& is, Year& y)
// read a year from is into y
// format: { year 1972 . . . }
{
    char ch;
    is >> ch;
    if (ch!='{')
    {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }
    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker!="year") error("bad start of year");
    y.year = yy;
    while(true)
    {
        Month m; // get a clean m each time around
        if(!(is >> m)) break;
        y.months[m.month] = m;
    }
    end_of_loop(is,'}',"bad end of year");
    return is;
}
ostream& operator<<(ostream& os, Year& y)
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 1 ; j <= 31 ; j++)
        {
            for(int k = 0 ; k < 24 ; k++)
            {
                if(y.months[i].days[j].hours[k] != not_a_reading){
                    os << setw(12) << right << y.year << "|";
                    os << setw(12) << right << int_to_month(y.months.at(i).month) << "|";
                    os << setw(12) << right << j << "|";
                    os << setw(12) << right << k  << "|";
                    os << setw(12) << right << setprecision(2) << fixed <<  y.months[i].days[j].hours[k] << "|" << endl;
                } 
            }
        }
    }
    return os;
}
 /*if (m.days[r.day].hours[r.hour] != not_a_reading)
                ++duplicates;
            m.days[r.day].hours[r.hour] = r.temperature;*/
            //.months[r].days[j.day].hours[k.hour]
           // y.months[i.month].days[j.day].hours[k.hour] 