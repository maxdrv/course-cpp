
class Player {

    // by default everything is private
public:
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }

};

int main() {
    Player player;  // we created new instance of player WTF???
    player.x = 5;  // now we are setting value


    player.Move(1, 2);  // calling method of Player
}