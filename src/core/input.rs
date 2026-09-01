use std::io::{stdout, Write};
use::crossterm::terminal;
use::crossterm::event;
use::crossterm::event::Event;
use::crossterm::event::KeyCode;
use crossterm::event::KeyEventKind;

pub fn read_input() -> String
{

    let mut input = String::new();
    terminal::enable_raw_mode().unwrap();

    loop {

        let terminal_event = event::read().unwrap();


        match terminal_event {
            Event::Key(key) => {

                if key.kind == KeyEventKind::Press // Checking if the key is pressed not released.
                {
                    match key.code  {

                        KeyCode::Enter => {
                            print!("\r\n"); // Beginning of the current line and new line.
                            stdout().flush().unwrap();
                            break;
                        }

                        KeyCode::Backspace => {
                            if input.pop().is_some() // is.some() returns some if it worked and none if input_buffer is empty.
                            {
                                print!("\x08 \x08"); // \x08 is just \b which refers to backspace.
                                stdout().flush().unwrap();
                            }
                        }

                        KeyCode::Char(c) => {
                            input.push(c); // Push the char c to string input buffer.
                            print!("{}", c);
                            stdout().flush().unwrap(); // Force print, usage of flush() and unwrap() to just unwrap the Result<> box and crash if failed.
                        }
                        _ => {}
                    }
                }
            }
            _ => {}
        }
    }

    terminal::disable_raw_mode().unwrap();

    //println!("{}", input_buffer); debug

    input  // In rust writing the return value at the end with no end omiter returns the value.
}
