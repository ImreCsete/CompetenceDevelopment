fn main() {
    let mut refers_nothing = dangle();

    println!("{}", refers_nothing);

    refers_nothing.push_str(", World!");

    let hello = &refers_nothing[0..5];

    println!("hello = {}", hello);

    let world = &refers_nothing[7..12];

    println!("world = {}", world);

}

fn dangle() -> String {
    let s = String::from("Hello");

    s
}
