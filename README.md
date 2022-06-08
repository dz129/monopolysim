# monopolysim
Monopoly Simulation

This program allows for full monopoly games to be simulated by bots with mechanics such as buying, trading, and dice rolling embedded into the system.

The goal of the simulation is to gather data from monopoly games without actually playing (ie. best color, best squares, etc) and then use python file reading to analyse the data (i hate c++ file reading).
Right now I have a decent version of the simulator running (althought it wont loop to get multiple games at once so i have to manually start a new one) that I would like to make several imporvments on.
However, I wanted to post it on here just to get it ready for future updates. 

Reflection so far:

(6/8/22)

Made my first update to the github ever, pretty happy with the automation feature that I added (basically realized what I was doing wrong before). However, an infinite loop keeps happening at random. I want to work hard to fix that before I start fixing up the trading system. 

(6/7/22)

I definately applied a lot of the stuff that I am currently learning into this project (linked lists, OOP, etc) and am happy with how far I came with it. Originally I got the idea from a youtube video that ran simulations of monopoly to apply to machine learning. However, I just wanted to make a simulation that played games as long as possible.
I think it has been a pretty successful project so far and I'm proud of myself since this is the longest one I've done (and it's still not done!). The major hiccups I've had were things like segmentation errors and trying to overcome that as well as getting everything to get in unision.
The thing i need to improve on the most is planning ahead. Oh my god. If i planned most of this ahead, I could have avoided a lot of errors, so next time I will be less hasty in starting projects, still a really great learning experience so far.

This is a barebones version of the final product, I will be adding to it as the weeks go.
A couple missing features and glitches right now are:
1. Hotel and House purchasing by the robots: The robots currently cannot purchase houses
2. intelligent trading: The robots are able to trade right now, but not intelligently. If one robot is close to a monopoly, the other robot will jsut give then that monopoly (given that they have the piece to complete it). I want to implement a system where both bots "negociate with each other" but that might be a pretty tough task right now.
3. Go to jail rolls: Typically in a real game of monopoly, the player is able to choose to roll to get out, but right now the bots can only pay fifty dollars to get out.
4. O(1) time complexity features: Right now if there needs to be an update for a spot, it requires a pointer to traverse the whole linked list. 
5. Segmentation Error at the end of each run: The program works fine, but I wanted to automate it so it could just run for an extended period of time to collect data. However, everytime i do that, a segmentation error happens at the end of the game (everything else works fine)
6. Simple AI: I want robots to know which properties are good and which ones are bad through data analysis done by the python script.
