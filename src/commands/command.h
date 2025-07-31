#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    virtual ~Command() = default;

    static void execute(Command &&command) {
        return command.execute();
    }

private:
    virtual void execute() = 0;
};

#endif //COMMAND_H
