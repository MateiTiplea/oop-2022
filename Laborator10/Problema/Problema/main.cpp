#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <functional>
#include <iostream>

using namespace std;

// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of
// {"a.jpg", "b.jpg"} no global(or statics!) variables allowed

class CommandManager {
  private:
    map<string, function<void(vector<string>)>> commands;

  public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at
    // https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run() {
    string comanda;
    vector<string> argumente;
    getline(cin, comanda);
    while (comanda != "stop") {
        char* p;
        p = strtok(&comanda[0], " ");
        argumente.clear();
        while (p != NULL) {
            argumente.push_back(p);
            p = strtok(NULL, " ");
        }
        auto v = commands.find(argumente[0]);
        if (v == commands.end()) {
            printf("\n\tFunctia nu este definita \n");
        } else {
            argumente.erase(argumente.begin());
            v->second(argumente);
        }
        getline(cin, comanda);
    }
}

int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](vector<string> args) {
        printf("\n\tNumber of arguments is: %u \n", static_cast<unsigned>(args.size()));
    };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [&number_of_errors](vector<string> args) {
        FILE* fisier = fopen(args[0].c_str(), "a");
        if (fisier == nullptr) {
            number_of_errors++;
            return;
        }

        vector<string>::iterator it;
        it = args.begin();
        it++;
        while (it != args.end()) {
            fwrite(it->c_str(), sizeof(char), it->size(), fisier);
            it++;
        }
        fclose(fisier);
    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [n = 0](vector<string> args) mutable {
        printf("\t\nThe number of times the function was called is: %d \n", n);
        n++;
    };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    // auto copy = ...;
    // manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    // auto sort_size = ...;
    // manager.add("sort_size", sort_size);

    // add one more command of anything you'd like

    manager.run();

    printf("number of errors: %u\ndone!\n", number_of_errors);
}
