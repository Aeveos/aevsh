#[derive!(Debug, PartialEq, Clone)]
enum Token {

    // Quoted and non quoted words.
    Word(String),
    Newline(),
    EOL,

    // Redirection
    Pipe(String),
    RedirIn(String),    // <
    RedirOut(String),   // >
    RedirAppend(String),    // >>

    // Operators

    Add(String),
    AndIf(String),
    OrIf(String),
    Semicolon(String),

    // Path
    Slash(String),
    Escape(String),
}

enum State {
    Start,
    InWord,
    InQuotes,
    InPipe,
    InLess,
    InGreater,
    InEscape,
}








