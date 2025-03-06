//Keys and Rooms

class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size();
            vector<bool> visited(n, false);
            
            // Start DFS from room 0
            dfs(rooms, 0, visited);
            
            // Check if all rooms have been visited
            for (bool room : visited) {
                if (!room) return false;
            }
            
            return true;
        }
        
    private:
        void dfs(vector<vector<int>>& rooms, int currentRoom, vector<bool>& visited) {
            // If this room has already been visited, return
            if (visited[currentRoom]) return;
            
            // Mark current room as visited
            visited[currentRoom] = true;
            
            // Visit all rooms that can be unlocked by keys in this room
            for (int key : rooms[currentRoom]) {
                dfs(rooms, key, visited);
            }
        }
    };

