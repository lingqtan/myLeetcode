class Solution {
public:
    const int MAX_LEN = 105;
    
    string purify_local(string local_name) {
        char cstr_purify[MAX_LEN];
        int j = 0;
        for (int i = 0; i < local_name.length(); i++) {
            char c = local_name[i];
            if (c == '.') continue;
            if (c == '+') break;
            cstr_purify[j++] = c;
        }
        cstr_purify[j] = '\0';
        string purify = cstr_purify;
        return purify;
    }

    int numUniqueEmails(vector<string>& emails) {
        std::set<std::pair<string, string> > pure_emails;
        for (int i = 0; i < emails.size(); i++) {
            string email = emails[i];
            int sep = email.find('@');
            if (sep == -1) continue;
            string local_name = email.substr(0, sep);
            string domain_name = "";
            if (sep < email.length()-1) 
                domain_name = email.substr(sep+1, email.length()-1-sep);
            string pure_local_name = purify_local(local_name);
            pure_emails.insert(std::pair(pure_local_name, domain_name));
        }
        return pure_emails.size();
    }
};