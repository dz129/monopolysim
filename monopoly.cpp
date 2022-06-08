#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <fstream>
// different types of spaces: jail, go, community chest, chance, property, railroad, utility
struct space{
    int owned;
    int cost;
    int charge;
    int house;
    int house1;
    int house2;
    int house3;
    int hotel;
    int numhouses;
    int numhotel;
    int housecost;
    bool monostat;
    std::string name;
    std::string type;
    std::string color;
    space* next;
};
space* head = NULL;
space* tail = NULL;

//data trackers are here
std::vector<std::string> colorfrequency;
std::vector<std::string> propfrequencey;
//going to add tracker that tracks how much money each property makes
std::vector<std::vector<std::string>> proptracker;
std::vector<std::vector<std::string>> colortracker;
//tracks which properties players have based on color, only need to track colors because the monopoly mechanic
//the payment mechanic accounts for which properties players have


//tracks the balances for each player
std::vector<int> balances;
int bank = 100000;

void insert(int owned = -1, int cost =0, int charge =0, int house =0, int house1 =0, int house2 =0, int house3 =0, int hotel=0, std::string name ="", std::string type ="",std::string color ="", int numhouses = 0, int numhotel = 0, int housecost = 0, bool monostat = false){
    //inserts everthing into the linked list
    space* temp = new space;
    temp -> owned = owned;
    temp -> charge = charge;
    temp -> cost = cost;
    temp -> house = house;
    temp -> house1 = house1;
    temp -> house2 = house2;
    temp -> house3 = house3;
    temp -> name = name;
    temp -> type = type;
    temp -> color = color;
    temp -> housecost = housecost;
    temp -> numhouses = numhouses;
    temp -> numhotel = numhotel;
    temp -> monostat = monostat;
    if ((head == NULL) && (tail == NULL)){
        head = tail = temp;
        return;
    }
    tail -> next = temp;
    temp -> next = NULL;
    tail = temp;
}
void buildboard(){
    //void insert(int owned = -1, int cost, int charge, int house, int house1, int house2, int house3, int hotel, std::string name, std::string type)
    // different types of spaces: jail, go, community chest, chance, property, railroad, utility, tax, empty(free parking and jail)
    //color, base color is white
    insert(-1,0,0,0,0,0,0,0,"Go","go","white",0,0,0,false);
    insert(-1, 60, 4,10,30,90,160,250,"Mediterranean Avenue","property","brown",0,0,50,false);
    insert(-1,0,0,0,0,0,0,0,"Community Chest", "community","white",0,0,0,false);
    insert(-1,60,4,20,60,180,320,450,"Baltic Ave", "property","brown",0,0,50,false);
    insert(-1,0,0,0,0,0,0,0,"Income Tax", "tax","white",0,0,0,false);
    insert(-1,200,25,50,100,200,0,0,"Reading Railroad", "railroad", "railroad",0,0,0,false);
    insert(-1,100,6,30,90,270,400,550,"Oriental Ave", "property", "lblue",0,0,50,false);
    insert(-1,0,0,0,0,0,0,0,"Chance","chance","white",0,0,0,false);
    insert(-1,100,6,30,90,270,400,550,"Vermont Ave","property","lblue",0,0,50,false);
    insert(-1,120,8,40,100,300,450,600,"Connecticut Ave", "property", "lblue",0,0,50,false);
    insert(-1,0,0,0,0,0,0,0,"Jail","empty","white",0,0,0,false);
    insert(-1,140,10,50,150,450,625,750,"St Charles Place", "property","pink",0,0,100,false);
    insert(-1,150,0,0,0,0,0,0,"Electric Company","utility","white",0,0,0,false);
    insert(-1,140,10,50,150,450,625,750,"States Avenue", "property","pink",0,0,100,false);
    insert(-1,160,12,60,180,500,700,900,"Virginia Ave","property","pink",0,0,100,false);
    insert(-1,200,25,50,100,200,0,0,"Pennsylvania Railroad", "railroad","white",0,0,0,false);
    insert(-1,180,14,70,200,550,750,950,"St James Place","property","orange",0,0,100,false);
    insert(-1,0,0,0,0,0,0,0,"Community Chest", "community","white",0,0,0,false);
    insert(-1,180,14,70,200,550,750,950,"Tennessee Avenue","property","orange",0,0,100,false);
    insert(-1,200,16,80,220,600,800,1000,"New York Ave", "property","orange",0,0,100,false);
    insert(-1,0,0,0,0,0,0,0,"Free Parking","empty","white",0,0,0,false);
    insert(-1,220,18,90,250,700,875,1050,"Kentucky Ave","property","red",0,0,150,false);
    insert(-1,0,0,0,0,0,0,0,"Chance","chance","white",0,0,0,false);
    insert(-1,220,18,90,250,700,875,1050,"Indiana Avenue","property","red",0,0,150,false);
    insert(-1,240,20,100,300,750,925,1100, "Illinois Ave", "property","red",0,0,150,false);
    insert(-1,200,25,50,100,200,0,0,"B&O Railroad", "railroad","white",0,0,0,false);
    insert(-1,260,22,110,330,800,975,1150,"Atlantic Ave","property","yellow",0,0,150,false);
    insert(-1,260,22,110,330,800,975,1150,"Ventnor Avenue","property","yellow",0,0,150,false);
    insert(-1,150,0,0,0,0,0,0,"Water Works","utility","white",0,0,0,false);
    insert(-1,280,24,120,360,850,1025,1200,"Marvin Gardens","property","yellow",0,0,150,false);
    insert(-1,0,0,0,0,0,0,0,"Go to Jail","jail","white",0,0,0,false);
    insert(-1,300,26,130,390,900,1100,1275,"Pacific Avenue","property","green",0,0,200,false);
    insert(-1,300,26,130,390,900,1100,1275,"North Carolina Avenue","property","green",0,0,200,false);
    insert(-1,0,0,0,0,0,0,0,"Community Chest", "community","white",0,0,0,false);
    insert(-1,320,28,150,450,1000,1200,1400,"Pennsylvania Avenue","property","green",0,0,200,false);
    insert(-1,200,25,50,100,200,0,0,"Short Line", "railroad","white",0,0,0,false);
    insert(-1,0,0,0,0,0,0,0,"Chance","chance","white",0,0,0,false);
    insert(-1,350,35,175,500,1100,1300,1500,"Park Place", "property","blue",0,0,200,false);
    insert(-1,0,0,0,0,0,0,0,"Luxury Tax", "tax","white",0,0,0,false);
    insert(-1,400,50,200,600,1400,1700,2000,"Boardwalk", "property","blue",0,0,200,false);
    //makes sure that boardwalk is connected to go
    tail -> next = head;
}
void printboard(){
    space* tempx = head;
    for (int i = 0; i < 40; i++){
        std::string nm = tempx -> name;
        std::cout << nm << "\n";
        tempx = tempx -> next;
    }
}

class player{
    private:

    bool jailstatus = false;
    int balance = 1500;
    int dice1;
    int dice2;
    int roll;
    int numrail = 0;
    int numhouse = 0;
    int numhotel = 0;
    space* temp = head;
    int gotojail = 10;
    int jailrolls = 3;
    int turnnum = 0;
    std::vector<std::string> props;
    public:

    int ownernum;
    player(){
        //constructor to make the vectors needed
        balances.push_back(balance);
        proptracker.push_back(props);
    }

    void buyprop(){
        //buys the property
        //might want to have a condition for this like "if the player has this amount of money, buy, if less, dont buy"
        //specify condition in traversal function
        temp -> owned = ownernum;
        int price = temp -> cost;
        balances[ownernum] -= price;
        proptracker[ownernum].push_back(temp -> color);
    }
    void pay(){
        //charges the player based on monopoly,houses, and hotels
        if (temp -> type == "property"){
            int pay = temp -> charge;
            if (temp -> monostat == true){
                if (temp -> numhotel == 0 && temp -> numhouses == 0)pay *= 2;
                else if (temp -> numhotel == 1) pay = temp -> hotel;
                else if (temp -> numhotel == 0 && temp -> numhouses > 0){
                    if (temp -> numhouses == 1) pay = temp -> house;
                    if (temp -> numhouses == 2) pay = temp -> house1;
                    if (temp -> numhouses == 3) pay = temp -> house2;
                    if (temp -> numhouses == 4) pay = temp -> house3;
                }
            }
        int owner = temp -> owned;
        balances[ownernum] -= pay;
        balances[owner] += pay;
        }
        if (temp -> type == "railroad"){
            int pay = temp -> charge;
            if (temp -> numhotel == 0 && temp -> numhouses > 0){
                if (temp -> numhouses == 1) pay = temp -> house;
                if (temp -> numhouses == 2) pay = temp -> house1;
                if (temp -> numhouses == 3) pay = temp -> house2;
                }
            }
        if (temp -> type == "tax"){
            balances[ownernum] -= 100;
        }
        if (temp -> type == "utility"){
            balances[ownernum] -= 70;
        }
    }
    void traversal(){
        //traverse the linked list
        //this traverses for one roll
        //called twice to account for two dice being rolled
        //dont know why it wont work if i try to use two dice
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
        dice1 = dist6(rng);
        for (int i = 0; i < dice1; i++){
            temp = temp -> next;
            if (temp -> type == "Go" && jailstatus == false){
                balances[ownernum] += 200;
            }
        
        }
    }
    void jailtraverse(){
        temp = head;
        for (int i = 0; i < 10; i++){
            temp = temp -> next;
        
        }
    }
    //the idea for chance and community chest is that it selects a random number and then based on that number does something
    void communitychest(){
    //if the player lands on a community chest tile, it takes a random card
    //might want to change this to a stack 
    int roll;
    int min = 1; // the min number a die can roll is 1
    int max = 7;// this->dieSize; // the max value is the die size
    int chest = rand() % (max - min + 1) + min;
    std::cout << "chest" <<chest << "\n";
    if (chest == 1){
        //pass go
        std::cout << "pass go" << "\n";
        temp = head;
        balances[ownernum] += 200;
    }
    if (chest == 2){
        //some story thing
        std::cout << "add 200" << "\n";
        balances[ownernum] += 200;
    }
    if (chest == 3){
        //go to jail
        std::cout << "gotojail" << "\n";
        temp = head;
        for(int i = 0; i < gotojail; i++){
            temp = temp-> next;
        }
        jailstatus = true;
    }
    if (chest == 4){
        //some story
        std::cout << "minus 100" << "\n";
        balances[ownernum] -= 100;
    }
    if (chest == 5){
        //pay this for amount of houses and hotels
        std::cout << "pay 40 for houses, pay 115 for num hotels" << "\n";
        balances[ownernum] -= ((40 * numhouse) + ( 115 * numhotel));
    }
    if (chest == 6){
        //some story
        std::cout << "minus 50" << "\n";
        balances[ownernum] -= 50;
    }
    if (chest == 7){
        //some story    
        std::cout << "add 15" << "\n";
        balances[ownernum] += 15;
    }
    }
    void chance(){
    //if the player lands on a chance tile, it takes a random card
    //might want to change this to a stack 
    int roll;
    int min = 1; // the min number a die can roll is 1
    int max = 7;// this->dieSize; // the max value is the die size
    int chance = rand() % (max - min + 1) + min;
    std::cout << "chanceroll :" << roll << "\n";
    if (chance == 1){
        std::cout << "add 200" << "\n";
        temp = head;
        balances[ownernum] += 200;
    }
    if (chance == 2){
        std::cout << "boardwalk" << "\n";
        //sends to boardwalk since that is where tail will be on the final board
        temp = tail;

        if (temp -> owned != -1){
        pay();
        }
        if (temp -> owned == -1){
        buyprop();
        }
        
    }
    if (chance == 3){
        //send to next railroad
        std::cout << "next rail" << "\n";
        while( temp -> type != "railroad"){
            temp = temp -> next;
        }
        temp -> next;
        if (temp -> owned != -1){
        pay();
        }
        if (temp -> owned == -1){
        numrail += 1;
        buyprop();
        }

        //function for paying railroad
        //fuunction for buying prop
    }
    if (chance == 4){
        //some story
        std::cout << "minus 100" << "\n";
        balances[ownernum] -= 100;
    }
    if (chance == 5){
        //give 50 to every player
        std::cout << "give 50 to every player" << "\n";
        for (int i = 0; i < balances.size(); i++){
            if (i != ownernum){
                balances[ownernum] -= 50;
                balances[i] += 50;
            }
        }
    }
    if (chance == 6){
        //go to jail
        std::cout << "gotojail" << "\n";
        temp = head;
        jailstatus = true;
        jailtraverse();

    }
    if (chance == 7){
        std::cout << "next utility" << "\n";
        while( temp -> type != "utility"){
            temp = temp -> next;
        }
        temp -> next;
        if (temp -> owned != -1){
        pay();
        }
        if (temp -> owned == -1){
            buyprop();
        }
    }
    }
    void jail(){

    }

    // this will go after a roll to check the stats of the square 
    void checkspacestatus(){
        //checks the type of space that the player is currently on and what actions to take accordingly
        std::cout << "type"<< temp -> type << "name" << temp -> name << "color" << temp -> color << "\n";
        propfrequencey.push_back(temp -> name);
        colorfrequency.push_back(temp -> color);
        if (temp -> type == "property"){
            if (temp -> owned != -1){
                pay();
            }
            if (temp -> owned == -1){
                if (balances[ownernum] > 200){
                buyprop();
                }
            }
        }
        if (temp -> type == "jail"){
            temp = head;
            jailstatus = true;
            jailtraverse();
        }
        if (temp -> type == "railroad"){
            if (temp -> owned != -1){
                pay();
            }
            if (temp -> owned == -1){
                buyprop();
                numrail += 1;
            }
        }
        if (temp -> type == "community"){
            communitychest();
        }
        if (temp -> type == "chance"){
            chance();
        }
        if (temp -> type == "tax"){
            pay();
        }
        if (temp -> type == "utility"){
            if (temp -> owned != -1){
                pay();
            }
            if (temp -> owned == -1){
                if (balances[ownernum] > 200){
                buyprop();
                }
            }
        }
        if(temp -> type == "go"){
            //do nothing because the traversal function already accounts for passing go
        }
        if (temp -> type == "empty"){

        }

        
    }

    void checkjail(){
        if (jailstatus == true){
            //checks if the player is in jail and basically says you need to roll doubles or stay stuck
            //this needs to be updated because this all happens within a turn
            //adjust it so it happens for a singular turn
            balances[ownernum] -= 50;
            jailstatus = false;
        }
    }
    void enactmonopoly(std::string color){
        std::cout << "enacting monopoly" << "\n"; 
        //This function makes a property a monopoly by changing the monostatus from false to true
        space* mono = head;
        for (int i = 0; i < 40; i++){
            if (mono-> color == color){
                mono -> monostat = true;
                mono -> owned = ownernum;
            }
        }
    }



    void checkmonopoly(){
        std::cout << "checking monopoly" << "\n";
        //checks if the player has a monopoly on anything, if there is, a temporary pointer traverses the list and changes the monopoly status of the colored properties to true
        int blue = 0;
        int brown = 0;
        int lblue = 0;
        int pink = 0;
        int orange = 0;
        int red = 0;
        int yellow = 0;
        int green = 0;
        for (int i = 0; i < proptracker[ownernum].size(); i++){
            if (proptracker[ownernum][i] == "red") red += 1;
            if (proptracker[ownernum][i] == "brown") red += 1;
            if (proptracker[ownernum][i] == "lblue") red += 1;
            if (proptracker[ownernum][i] == "pink") red += 1;
            if (proptracker[ownernum][i] == "orange") red += 1;
            if (proptracker[ownernum][i] == "blue") red += 1;
            if (proptracker[ownernum][i] == "yellow") red += 1;
            if (proptracker[ownernum][i] == "green") red += 1;
        }
        if (blue == 2){
            enactmonopoly("blue");
        }
        if (brown == 2){
            enactmonopoly("brown");
        }
        if (red == 3){
            enactmonopoly("red");
        }
        if (lblue == 3){
            enactmonopoly("lblue");
        }
        if (pink == 3){
            enactmonopoly("pink");
        }
        if (orange == 3){
            enactmonopoly("orange");
        }
        if (yellow == 3){
            enactmonopoly("yellow");
        }
        if (green == 3){
            enactmonopoly("green");
        }
    }        
    
    void trade(int ownernum, int tradernum, std::string color){
        for (int i = 0; i < colortracker[ownernum].size(); i++){
            for(int j = 0; j < colortracker[tradernum].size(); j++){
                if (colortracker[tradernum][j] == color){
                    colortracker[ownernum].push_back(colortracker[tradernum][j]);
                    proptracker[ownernum].push_back(proptracker[tradernum][j]);
                }
            }
        }
        std::cout << "traded\n " << color ;
        checkmonopoly();
    }

    void attempttrade(std::string color){
        std::cout << "attempting trade for : "<< color << "\n";
        for(int i = 0; i < proptracker.size(); i++){
        if (i != ownernum){
        int blue = 0;
        int brown = 0;
        int lblue = 0;
        int pink = 0;
        int orange = 0;
        int red = 0;
        int yellow = 0;
        int green = 0;
        for (int j = 0; j < proptracker[i].size(); j++){
            if (proptracker[i][j] == "red") red += 1;
            if (proptracker[i][j] == "brown") red += 1;
            if (proptracker[i][j] == "lblue") red += 1;
            if (proptracker[i][j] == "pink") red += 1;
            if (proptracker[i][j] == "orange") red += 1;
            if (proptracker[i][j] == "blue") red += 1;
            if (proptracker[i][j] == "yellow") red += 1;
            if (proptracker[i][j] == "green") red += 1;
        }
        for (int j = 0; j < proptracker[i].size(); j++){
        if (j != ownernum){
        if (color == "blue" && blue == 1){
            trade(ownernum , j , "blue");
        }
        if (color == "brown" && brown == 1){
            trade(ownernum , j , "brown");
        }
        if (color == "red" && red == 1){
            trade(ownernum , j , "red");
        }
        if (color == "lblue" && lblue == 1){
            trade(ownernum , j , "lblue");
        }
        if (color == "pink" && pink == 1){
            trade(ownernum , j , "pink");
        }
        if (color == "orange" && orange == 1){
            trade(ownernum , j , "orange");
        }
        if (color == "yellow" && yellow == 1){
            trade(ownernum , j , "yellow");
        }
        if (color == "green" && green == 1){
            trade(ownernum , j , "green");
        }
        }
        }
        }
    }
    }
        void checkclosemonopoly(int numcheck){
            std::cout << "checking close" << "\n";
        //checks if the player has a monopoly on anything, if there is, a temporary pointer traverses the list and changes the monopoly status of the colored properties to true
        int blue = 0;
        int brown = 0;
        int lblue = 0;
        int pink = 0;
        int orange = 0;
        int red = 0;
        int yellow = 0;
        int green = 0;
        for (int i = 0; i < proptracker[numcheck].size(); i++){
            if (proptracker[numcheck][i] == "red") red += 1;
            if (proptracker[numcheck][i] == "brown") brown += 1;
            if (proptracker[numcheck][i] == "lblue") lblue += 1;
            if (proptracker[numcheck][i] == "pink") pink += 1;
            if (proptracker[numcheck][i] == "orange") orange += 1;
            if (proptracker[numcheck][i] == "blue") blue += 1;
            if (proptracker[numcheck][i] == "yellow") yellow += 1;
            if (proptracker[numcheck][i] == "green") green += 1;
        }
        if (blue == 1){
            attempttrade("blue");
        }
        if (brown == 1){
            attempttrade("brown");
        }
        if (red == 2){
            attempttrade("red");
        }
        if (lblue == 2){
            attempttrade("lblue");
        }
        if (pink == 2){
            attempttrade("pink");
        }
        if (orange == 2){
            attempttrade("orange");
        }
        if (yellow == 2){
            attempttrade("yellow");
        }
        if (green == 2){
            attempttrade("green");
        }
    }    
    void checkrail(){
        if (numrail > 1){
            space* rail = head;
            for(int i = 0; i < 40; i++){
                rail = rail -> next;
                if (rail -> type == "railroad" && rail -> owned == ownernum){
                    if (numrail == 2){
                        rail -> numhouses = 1;
                    }
                    if (numrail == 3){
                        rail -> numhouses = 2;
                    }
                    if (numrail == 4){
                        rail -> numhouses = 3;
                    }
                }
            }
        }
    }
    void turn(){
        std::cout << "player:" << ownernum << "\n";
        if (balances[ownernum] >= 0){
        checkjail();
        traversal();
        traversal();
        checkspacestatus();
        std::cout <<"balance" <<balances[ownernum] << "\n";
        checkmonopoly();
        checkrail();
        turnnum += 1;
        //if (turnnum % 3 == 0 && turnnum > 1) checkclosemonopoly(ownernum);
        }
    }
};

bool checkwinner(){
    std::vector<int> players;
    for (int i = 0; i < balances.size(); i++){
        if (balances[i] >= 0){
            players.push_back(i);
        }
    }
    if (players.size() > 1) return true;
    if (players.size() == 1) return false;
    return true;
}

int main(){
    for (int i = 0; i < 100; i++){
    propfrequencey.clear();
    colorfrequency.clear();
    balances.clear();
    proptracker.clear();
    colortracker.clear();
    buildboard();
    player p1;
    player p2;
    player p3;
    p1.ownernum = 0;
    p2.ownernum = 1;
    p3.ownernum = 2;
    while(checkwinner()){
        p1.turn();
        p2.turn();
        p3.turn();
        }
    for (int i = 0; i < balances.size(); i++){
        if (balances[i] > 0){
            std::cout << "The Winner is: player " << i << "\n";
            std::ofstream winnerx;
            winnerx.open("winner.txt", std::ios_base::app);
            winnerx << i << "\n";
        }
    }
    std::ofstream f;
            f.open("color.txt", std::ios_base::app);
            if (f.is_open()){
                std::cout << "color open";
                for (int i = 0; i < colorfrequency.size(); i++){
                    f << colorfrequency[i] << "\n";
                    std::cout << "wrote";
                }
                f.close();
            }
    std::ofstream f2;
            f2.open("prop.txt", std::ios_base::app);
            if (f2.is_open()){
                std::cout << "prop open";
                for (int i = 0; i < colorfrequency.size(); i++){
                    f2 << propfrequencey[i] << "\n";
                    std::cout << "wrote";
                }
                f2.close();
    }
    }
}









