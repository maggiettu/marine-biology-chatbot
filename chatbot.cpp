#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Chatbot
{
public:
	// returns the name of this chatbot
	virtual string name() const = 0;

	// gives a string to this chatbot
	virtual void give_to(const string &s) = 0;

	// gets a string from this chatbot
	virtual string get_from() = 0;

	// virtual destructor
	virtual ~Chatbot() {}

}; // class Chatbot

class Turing_bot: public Chatbot {
    string bot_name;
    string reply;

    string say_hello() {
        return "Hello! My name is " + bot_name + ", i'm a marine biologist here at the Cmpt Aquarium :) \n"
        + "I can tell you which animals here at our exhibits are active during this time of day, tell you about my favourite animals, or about what fish you can catch this season!\n"
        + "If you have a specific animal you'd like to learn about, just let me know!";
    }

    string say_goodbye() {
        return "Thanks for chatting with me, I hope you learned something new about our marine life! Hope to see you visit again :)";
    }

    string my_favourite() {
        return "the spot of my favourite aquatic mammal has to go to the orca! As for fish, jellyfish are my favourite!";
    }

    string get_time() {
        // current date/time based on current system
        time_t now = time(0);
        tm *ltm = localtime(&now);

        // https://seamor.org/what-time-of-day-are-dolphins-most-active/
        int hour = ltm->tm_hour;
        if (0 <= hour && hour <= 5) {
            return " Many deep-sea creatures are adapted to the darkness of the deep ocean and may be more active during these nighttime hours.";
        } else if (5 < hour && hour <= 10) {
            return "the best time to go dolphin watching is now, during the morning, as you'll have good visibility and dolphins are active during this period!";
        } else if (10 < hour && hour <= 4) {
            return "Marine species inhabiting coral reef ecosystems, such as reef fish, coral polyps, and invertebrates, are more active now since water temperatures are warmer and sunlight is abundant!";
        } else {
            return "As the sun sets, fishes, squids, shrimps and zooplankton make massive migrations from the dark ocean depths upward to near the ocean's surface.";
        }
    }

    // https://www.beasleysfishingcharters.ca/links-info/fishing-calendar
    string get_fish_season() {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int month = 1 + ltm->tm_mon;
        if (month == 1|| month == 2) {
            return "The fish in season are Winter Spring Salmon, and Steelhead!";
        } else if (month == 3 || month == 4) {
            return "The fish in season are Halibut, Winter Spring Salmon, Steelhead, and Trout";
        } else if (month == 5 || month == 6 || month == 7) {
            return "The fish in season are Halibut and Spring Salmon";
        } else if (month == 8 || month == 9) {
            return "The fish in season are Halibut, Lingcod and Large Spring Salmon";
        } else if (month == 10 || month == 11) {
            return "The fish in season are Halibut and River salmon";
        } else {
            return "The fish in season are Halibut, Winter Spring Salmon, and Steelhead";
        }
    }

    // https://www.wwf.org.uk/learn/fascinating-facts/dolphins
    string get_dolphin_fact() {
        vector<string> dolphin_facts;
        dolphin_facts.push_back("There are 36 species of marine dolphins - living in nearly all aquatic environments, including oceans, coastal, estuarine and freshwater!");
        dolphin_facts.push_back("Bottlenose dolphins are one of the few species that have the ability to recognise themselves in a mirror!");
        dolphin_facts.push_back("Dolphins are marine mammals. They must surface to breathe air and give birth to live young.");
        dolphin_facts.push_back("A group of dolphins is called a pod!");
        int index = rand() % dolphin_facts.size();
        return dolphin_facts[index];
    }

    // https://www.livescience.com/55478-octopus-facts.html
    string get_octopus_fact() {
        vector<string> octopus_facts;
        octopus_facts.push_back("To swim, octopuses suck water into their bodies and shoot it out a tube called a siphon.");
        octopus_facts.push_back("Octopuses have three hearts and blue blood!");
        octopus_facts.push_back("Octopuses have short life spans, some species only live for around six months. :(");
        octopus_facts.push_back("Some species of octopus, such as the mimic octopus, can mimic the appearance and behavior of other marine animals to deter predators or ambush prey.");
        int index = rand() % octopus_facts.size();
        return octopus_facts[index];
    }

    // https://morefundiving.com/20-incredible-marine-life-facts/
    string get_random_fact() {
        vector<string> ocean_facts;
        ocean_facts.push_back("The ocean covers more than 70% of the Earth's surface.");
        ocean_facts.push_back("Sponges are older than dinosaurs!");
        ocean_facts.push_back("Coral reefs play an important role in protecting coastal communities from storms and water surges.");
        ocean_facts.push_back("More than 80% of the ocean remains unexplored and unmapped.");
        ocean_facts.push_back("The ocean is home to an estimated 230,000 known species, but many more species have yet to be discovered.");
        int index = rand() % ocean_facts.size();
        return ocean_facts[index];
    }

    // https://www.wwf.org.uk/learn/fascinating-facts/top-10-facts-about-whales
    string get_whale_fact() {
        vector<string> whale_facts;
        whale_facts.push_back("Blue whales are the largest animals on Earth, with adults reaching lengths of up to 100 feet and weighing as much as 200 tons.");
        whale_facts.push_back("They have a heart the size of a small car and a tongue that can weigh as much as an elephant.");
        whale_facts.push_back("Blue whales are filter feeders, consuming massive amounts of krill and small fish by engulfing large volumes of water and filtering out the prey using baleen plates in their mouths.");
        whale_facts.push_back("Gray whales make one of the longest annual migrations of any mammal: they travel about 16,000 km round trip!");
        whale_facts.push_back("Humpback whales dont eat for most of the year, they live off fat reserves for 5.5-7.5 months!");
        int index = rand() % whale_facts.size();
        return whale_facts[index];
    }

    // https://uk.whales.org/whales-dolphins/facts-about-orcas/
    string get_orca_fact() {
        vector<string> orca_facts;
        orca_facts.push_back("Orcas are actually dolphins!");
        orca_facts.push_back("Orcas hunt everything from fish to walruses, seals, sea lions, penguins, squid, sea turtles, sharks, and even other kinds of whales.");
        orca_facts.push_back("Average-sized orcas may eat about 500 pounds of food a day!");
        orca_facts.push_back("Groups of orcas cooperate to herd fish into a compact area so that they're easier to eat.");
        int index = rand() % orca_facts.size();
        return orca_facts[index];
    }

    // https://www.wwf.org.uk/learn/fascinating-facts/sharks
    string get_shark_fact() {
        vector<string> shark_facts;
        shark_facts.push_back("Sharks do not have bones, they are make of cartilage!");
        shark_facts.push_back("Shark skin feels exactly like sandpaper because it is made up of tiny teeth-like structures called placoid scales, also known as dermal denticles.");
        shark_facts.push_back("Whale sharks are the biggest fish in the ocean.");
        shark_facts.push_back("Many sharks have several rows of teeth and can lose and replace thousands of teeth in their lifetimes.");
        shark_facts.push_back("Sharks have been around for over 400 million years - long before dinosaurs.");
        int index = rand() % shark_facts.size();
        return shark_facts[index];
    }
  

    // https://www.cabq.gov/artsculture/biopark/news/10-cool-facts-about-penguins
    string get_penguin_fact() {
        vector<string> penguin_facts;
        penguin_facts.push_back("A group of penguins in the water is called a raft but on land they're called a waddle!");
        penguin_facts.push_back("Many male penguins gift female penguins with rocks in order to woo them.");
        penguin_facts.push_back("penguins have dense skeletons for easier diving.");
        penguin_facts.push_back("Emperors are the biggest of the 18 species of penguin found today, and one of the largest of all birds.");
        int index = rand() % penguin_facts.size();
        return penguin_facts[index];
    }
    // https://blog.padi.com/7-facts-about-sea-lions/
    string get_sea_lion_fact() {
        vector<string> sea_lion_facts;
        sea_lion_facts.push_back("Sea lions are excellent swimmers and can reach speeds up to 25 miles per hour!");
        sea_lion_facts.push_back("Male sea lions are called bulls, females are called cows, and the young are called pups.");
        sea_lion_facts.push_back("Sea lions have a thick layer of blubber to help keep them warm in cold waters.");
        int index = rand() % sea_lion_facts.size();
        return sea_lion_facts[index];
    }

    string get_jellyfish_fact() {
        vector<string> jellyfish_facts;
        jellyfish_facts.push_back("Jellyfish are composed of over 95% water!");
        jellyfish_facts.push_back("Some jellyfish are capable of glowing in the dark, a phenomenon known as bioluminescence.");
        jellyfish_facts.push_back("Jellyfish have no brain, heart, or bones!");
        int index = rand() % jellyfish_facts.size();
        return jellyfish_facts[index];
    }

    string get_seal_fact() {
        vector<string> seal_facts;
        seal_facts.push_back("Seals are highly adapted for life in the water but can also spend time on land.");
        seal_facts.push_back("Seals have thick layers of blubber to keep them warm in cold waters.");
        seal_facts.push_back("Seals use their flippers to propel themselves through the water with grace.");
        int index = rand() % seal_facts.size();
        return seal_facts[index];
    }

    string get_otter_fact() {
        vector<string> otter_facts;
        otter_facts.push_back("Otters hold hands while sleeping to prevent drifting apart.");
        otter_facts.push_back("Otters have the densest fur of any mammal, with up to a million hairs per square inch!");
        otter_facts.push_back("Otters are excellent hunters, using their sharp claws to catch fish, crabs, and other prey.");
        int index = rand() % otter_facts.size();
        return otter_facts[index];
    }

public:

    // contructor 
    Turing_bot(string name): bot_name(name), reply("Hi! Welcome to the Cmpt Aquarium, i'm a marine biologist! What species would you like to learn about today?") {
        srand(time(nullptr)); // seed random number generator
    }

    // returns the name of this chatbot
    string name() const {return bot_name;}

    // gives a string to this chatbot
    void give_to(const string &s) {
        // convert to lowercase
        string str;
        for (char ch: s) {
            str += tolower(ch);
        }

        // specific facts, bot recognizes keywords and prints a random fact for that animal
        if (str.find("dolphin") != string::npos) {
            reply = get_dolphin_fact() +"\nIsn't that facinating!? What animal would you like to learn about next?";
        } else if (str.find("octopus") != string::npos) {
            reply = get_octopus_fact() + "\nI just love octopuses! What creature shall we explore next?";
        } else if (str.find("whale") != string::npos) {
            reply = get_whale_fact() + "\nWhales are so intruiging! What should we DIVE into next? haha.."; 
        } else if (str.find("orca") != string::npos || str.find("killer whale") != string::npos ) {
            reply = get_orca_fact() + "\norcas are my favourite animal :)! Do you want to learn more about orcas or do you have a specific animal in mind?";
        } else if (str.find("shark") != string::npos) {
            reply = get_shark_fact() + "\nSO COOL! What's next?";
        }  else if (str.find("sealion") != string::npos) {
            reply = get_sea_lion_fact() + "\nI cant believe I get to spend time with these amazing creatures! Which species do you want to know more about?";
        } else if (str.find("penguin") != string::npos) {
            reply = get_penguin_fact() + "\nI think they are just so adorable :)! Which species should we learn about now?";
        } else if (str.find("favourite") != string::npos) {
            reply = my_favourite() + "\nThanks for asking! Would you like to learn about which animals are active during this time of day or about this seasons fish?";
        } else if (str.find("jelly") != string::npos) {
            reply = get_jellyfish_fact() + "\nwow! What's next?";
        } else if (str.find("otter") != string::npos) {
            reply = get_otter_fact() + "\nWoah! Did you know that? What should be our next topic?";
        } else if (str.find("seal") != string::npos) {
            reply = get_seal_fact() + "\nWhat animal would you like to learn about next?";
        } else if (str.find("random") != string::npos) {
            reply = get_random_fact() + "\nWoah! Did you know that? What should be our next topic?";
        // functions to do with time, recognizes keywords and gets current date and time
        } else if (str.find("time") != string::npos || str.find("day") != string::npos ) {
            reply = get_time() + "\nDo you have a specific animal you want to learn more about, or would you like to hear about the fish of this season?";
        } else if (str.find("fish") != string::npos || str.find("season") != string::npos) {
            reply = get_fish_season() + "\nIf you do fish, do it sustainably! Now, do you have a specific animal you want to learn more about?";
        }

        // greetings and conversation
        else if (str.find("hello") != string::npos || str.find("hi") != string::npos) {
            reply = say_hello();
        } else if (str.find("bye") != string::npos || str.find("see you") != string::npos) {
            reply = say_goodbye();
        } 

        else {
            reply = "Sorry! I dont know what you mean... \n maybe I havent studied that species yet, you can ask me for a random fun fact or try another topic!";
        }

    }

    // gets a string from this chatbot
    string get_from() {return reply;}

    //destructor
    ~Turing_bot() {}
}; // class Turing_bot


void converse_with_user_first(Chatbot* bot) {
    int round_num = 1;
    string user_input;
    // print header
    cout << "Conversation with " << bot->name() << " (type !done to quit)" << endl << endl;
    
    while (true) {
        // get user input
        cout << "User " << round_num << "> ";
        getline(cin, user_input);

        // check for !done
        if (user_input == "!done") {
            cout << bot->name() << " " << round_num << "> !done" << endl << endl;
            cout << "User conversation with " << bot->name() << " ended" << endl;
            break;
        }
        // give bot input
        bot->give_to(user_input);

        // return bot input
        cout << bot->name() << " " << round_num << "> " << bot->get_from() << endl;
        cout<< endl;

        // increment 
        round_num++;
    }
}

void converse_with_user_second(Chatbot* bot) {
    int round_num = 1;
    string user_input;
    // print header
    cout << "Conversation with " << bot->name() << " (type !done to quit)" << endl << endl;
    
    while (true) {
        // print first reply 
        cout << bot->name() << " " << round_num << "> " << bot->get_from() << endl;
        // get user input
        cout << "User " << round_num << "> ";
        getline(cin, user_input);
        
        // check for !done
        if (user_input == "!done") {
            cout << "User conversation with " << bot->name() << " ended" << endl;
            break;
        }
        // give bot input
        bot->give_to(user_input);
        cout << endl;

        // increment 
        round_num++;
    }
}

int main()
{
   Turing_bot smart_bot("Shelly Shoresworth");
   converse_with_user_first(&smart_bot);
}