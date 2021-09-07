#include <iostream>
#include "Context.h"

class CommandInterpreter
{
public:
	void interpret(const std::string & cmd, Context & context)
	{
		if (cmd == "{")
		{
			context.openScope();
		}
		else if (cmd == "}")
		{
			context.closeScope();
		}
		else
		{
			context.addCommand(Command{ cmd });
		}
	}
};

int main()
{
	int staticBlockSize;
	std::cin >> staticBlockSize;

	{
		auto reactors{ std::make_unique<ReactorAggregation>() };
		reactors->addReactor(std::make_unique<ConsoleLogger>());

		Context context{ static_cast<size_t>(staticBlockSize) };
		context.setReactor(std::move(reactors));

		CommandInterpreter interpreter;

		std::vector<std::string> input{ "cmd1", "cmd2", "cmd3", "cmd4", "cmd5" };

		for (const auto & line : input)
		{
			interpreter.interpret(line, context);
		}
	}

	{
		auto reactors{ std::make_unique<ReactorAggregation>() };
		reactors->addReactor(std::make_unique<ConsoleLogger>());

		Context context{ static_cast<size_t>(staticBlockSize) };
		context.setReactor(std::move(reactors));

		CommandInterpreter interpreter;

		std::vector<std::string> input{
			"cmd1", "cmd2",
			"{",
				"cmd3", "cmd4",
			"}",
			"{",
				"cmd5", "cmd6",
				"{",
					"cmd7", "cmd8",
				"}",
				"cmd9",
			"}",
			"{",
				"cmd10", "cmd11"
		};

		for (const auto & line : input)
		{
			interpreter.interpret(line, context);
		}
	}

	std::cout << "Hello World!\n";
	std::cin >> staticBlockSize;

	return 0;
}
