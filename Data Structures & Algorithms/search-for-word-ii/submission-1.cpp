
class Solution {
   public:
    struct TrieNode {
        bool endOfWord;
        TrieNode* children[26];
        string word;

        TrieNode() {
            endOfWord = false;
            word = "";
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    vector<string> result;
    int r, c;

    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    TrieNode* getNode() { return new TrieNode(); }

    void insert(TrieNode* root, string& str) {
        TrieNode* crawl = root;

        for (char ch : str) {
            if (crawl->children[ch - 'a'] == nullptr) crawl->children[ch - 'a'] = getNode();

            crawl = crawl->children[ch - 'a'];
        }

        crawl->endOfWord = true;
        crawl->word = str;
    }

    void DFS(vector<vector<char>>& board, int i, int j, TrieNode* root) {
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] == '$' ||
            root->children[board[i][j] - 'a'] == nullptr)
            return;

        root = root->children[board[i][j] - 'a'];

        if (root->endOfWord) {
            result.push_back(root->word);
            root->endOfWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& p : directions) {
            DFS(board, i + p.first, j + p.second, root);
        }

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        result.clear();

        r = board.size();
        c = board[0].size();

        TrieNode* root = getNode();

        for (string& word : words) insert(root, word);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (root->children[board[i][j] - 'a']) DFS(board, i, j, root);
            }
        }

        return result;
    }
};