mod core;
mod frontend;

use std::io::{stdout, Write};
use core::input;
use frontend::lexer;

fn main() {

    println!("Aevsh v0.1.0");
    // stdout().flush().unwrap();

    loop {


        print!("\naevsh> ");
        stdout().flush().unwrap();

        let input_buffer = input::read_input();

        lexer::lexical_analyzer(input_buffer.clone());

    }
}