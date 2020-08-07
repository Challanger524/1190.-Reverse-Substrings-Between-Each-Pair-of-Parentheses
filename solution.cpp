class Solution {
public:
	string reverseParentheses(string &s) {
		size_t right;// bound side

		for (size_t i = 0; i < s.size(); /*+*/)
		{
			if (isalpha(s[i])) i++;//Iterate through the 'string'

			else //Untill we met a 'bracket'
			{
				if (s[i] == '(')//:Of "normal" kind
				{
					int parenthes = 0;
					right = i;

					while (right < s.size()) {//skip to the enclosing 'bracket'
						if (s[right] == '(') parenthes++;
						else if (s[right] == ')') parenthes--;

						right++;
						if (parenthes == 0) break;
					}
				}
				else if (s[i] == ')')//:Of "reverted" kind
				{
					int parenthes = 0;
					right = i;

					while (right < s.size()) {//skip to the enclosing 'bracket'
						if (s[right] == ')') parenthes++;
						else if (s[right] == '(') parenthes--;

						right++;
						if (parenthes == 0) break;
					}
				}

				//get rid of 'parentheses' (before and after the "encaved" substring)
				s.erase(--right, 1);
				s.erase(i, 1);
				right--;

				reverse(s.begin() + i, s.begin() + right);// substring, that was between 'parantheses'
				//cout << s <<endl;
			}
		}

		return s;
	}
};
