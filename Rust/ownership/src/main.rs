fn main() {
    let mut s = String::from("Hello"); // s stack, pointer, len, capacity hello index heap

    s.push_str(", world!");

    takes_ownership(&mut s);

    println!("{}", s);
    
    let x = 5;

    makes_copy(x);

}

fn takes_ownership(some_string: &mut String) {
    println!("{}", some_string);
    some_string.push_str("world");
}

fn makes_copy(some_integer: i32) {
    println!("{}", some_integer);
}