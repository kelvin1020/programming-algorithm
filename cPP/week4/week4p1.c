Complex & operator=(const string & s)
{
    int pos = s.find("+", 0);
    string sTmp = s.substr(0, pos);
    r = atof( sTmp.c_str() );
    sTmp = s.substr(pos + 1, s.length()-pos-2);
    i = atof(sTmp.c_str());
    return *this;
}