#include "detect.h"

static inline void ltrim(string& s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !isspace(ch);
            }));
}

// trim from end (in place)
static inline void rtrim(string& s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !isspace(ch);
            }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(string& s) {
    ltrim(s);
    rtrim(s);
}

string replace_st(string str, const string& toReplace, const string& replaceWith) {
    size_t pos = str.find(toReplace);

    while (pos != string::npos) {
        str.replace(pos, toReplace.length(), replaceWith);
        pos = str.find(toReplace, pos + replaceWith.length());
    }

    return str;
}


string getOpenTa(string t){
    int start = -1;
    int end = -1;
    start = t.find("<", 0);
    end = t.find(">", start);
    if (start != -1 && t[start + 1] != '/' && t[start + 1] != '?' && t[start + 1] != '!')
        return t.substr(start + 1, end - start - 1);
    else
        return "FALSE";
}


string getClosedTa(string t){
    int start = -1;
    int end = -1;
    start = t.find("/", 0);
    end = t.find(">", start);
    if (start != -1)
        return t.substr(start + 1, end - start - 1);
    else
        return "FALSE";
}

string getTagValu(string t){
    int start = -1;
    int end = -1;
    start = t.find(">", 0);
    end = t.find("/", start);
    if (start != -1)
        return t.substr(start + 1, end - start - 2);
    else
        return "FALSE";
}


std::vector<std::string> file_to_vecto(std::string file_data){
    std::vector<std::string> xml_file;

    std::istringstream oldfile(file_data);
    std::string tp;
    while (getline(oldfile, tp)) {

        trim(tp);
        xml_file.push_back(tp);

    }
    return xml_file;
}

bool error_detecto(string opent, string closedt, stack <string>& s, string& error_type){
    stack <string> temp;

    if (opent.compare("FALSE") && closedt.compare("FALSE"))
    {
        if (opent.compare(closedt))
        {
            error_type = "not matching tags: " + opent + " and " + closedt;
            return false;
        }
    }

    if (opent.compare("FALSE"))
    {
        s.push(opent);
    }
    if (closedt.compare("FALSE"))
    {
        if (!s.empty())
        {
            if (!closedt.compare(s.top()))
                s.pop();
            else                            //there is an error
            {
                while (!s.empty() && closedt.compare(s.top()))    //top not equal closed tag and stack is not empty
                {
                    temp.push(s.top());
                    s.pop();
                }
                if (s.empty())     //mean that it is a missed open tag = closedt
                {
                    error_type = "<" + closedt + ">";
                    while (!temp.empty())
                    {
                        s.push(temp.top());
                        temp.pop();
                    }
                }
                else              //mean that it is a missed closed tag = top of the stack
                {
                    s.pop();
                    while (!temp.empty())
                    {
                        s.push(temp.top());
                        temp.pop();
                    }
                    error_type = "</" + s.top() + ">";
                    s.pop();
                }
                return false;
            }
        }
        else
        {
            error_type = "<" + closedt + ">";
            return false; //error at location zero
        }
        return true;
    }
    return true;
}

vector <err_data> detect_erro(vector <string> xml_vector){
    vector <err_data> error_vector;
    err_data error;
    string error_type;
    stack <string> s;
    string line;
    int err_loc = -1;
    for (int i = 0; i < xml_vector.size(); i++)
    {
        line = xml_vector[i];
        string opent;
        string closedt;
        opent = getOpenTa(line);
        closedt = getClosedTa(line);

        if (opent.compare("FALSE") || closedt.compare("FALSE"))
        {
            if (!error_detecto(opent, closedt, s, error_type))
            {
                if (error_type.size() > 25)           //for mismatching tags
                {
                    error.err_type = error_type;
                    error.err_loc = i;
                    error_vector.push_back(error);
                }
                else
                {
                    error.err_type = error_type;
                    error.err_loc = i;
                    error_vector.push_back(error);
                }
            }
        }
    }
    int i = xml_vector.size();
    while (!s.empty())
    {
        string err = "</" + s.top() + ">";
        error.err_type = err;
        error.err_loc = i;
        error_vector.push_back(error);
        i++;
        s.pop();
    }
    return error_vector;
}

QString printErro (vector <err_data> error_vector) {
    QString errori;
    for (auto &i : error_vector) {
        int x=i.err_loc + 1;
        QChar myChar(x);

        QString myQString = QString::fromStdString(i.err_type);

        if (i.err_type.size() > 25) {
            errori=errori+ "Error at line " + QString::number(x)+ ": " + myQString + '\n';
        }
        else{
            errori=errori+ "Error at line " + QString::number(x)+": Missing" + myQString + '\n';
        }

    }

    return errori;
}