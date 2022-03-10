class Solution {
public:
    bool isValid(string s) {
        // Scanning
        // Go through, set three counters for different paranthesis
        // + when open, - if close
        // if one of the counters is not 0, means not closed or not opened before closing
        // What is correct order?
        // if means should be directly closed after opening, then
            // counters could be checked before increasing another one
            // no, order is like normal matching order, okay... so inner parenthesis must close first
            
        /* 
        int countera = 0, counterb = 0, counterc = 0;
        for(string::iterator it = s.begin(); it != s.end(); it++){
            switch(*it){
                case '(':

                    countera++;
                    break;
                case ')':

                    countera--;
                    break;
                case '{':

                    counterb++;
                    break;
                case '}':

                    counterb--;
                    break;
                case '[':

                    counterc++;
                    break;
                case ']':

                    counterc--;
                    break;
            }
                    
        }
        
        if (countera || counterb || counterc)
            return false;
        else
            return true;
        */
        
        // Maybe then change plans to using a stack or a queue to solve this
        // Scan string, push opening tags onto stack
        // When reach a closing tag, pop last pushed item from stack
        // if it matches with the closing tag, then is okay, continue, else return false
        // if no opening tag to match closing tag in string, means extra closing tag, return false
        // if stack isn't empty by end of string loop, return false as means not enough closing tags
        
        stack<char> openingtags;
        
        for(string::iterator it = s.begin(); it != s.end(); it++){
            if (*it == '{' || *it == '[' || *it == '('){
                openingtags.push(*it);
            } else {
                if (openingtags.empty())
                    return false;
                
                char matchingtag = openingtags.top();
                
                if(*it == '}' && matchingtag != '{')
                    return false;
                else if(*it == ']' && matchingtag != '[')
                    return false;
                else if(*it == ')' && matchingtag != '(')
                    return false;   
                
                openingtags.pop();
            }
        }
                               
        return openingtags.empty();
       
    }
};