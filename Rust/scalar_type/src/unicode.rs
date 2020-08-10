fn main() {
    let c = 'z';

    let f = 'Z';

    println!("c as char is {character1}\nc as ASCII is {ascii1}
             \nf as char is {character2}\nf as ASCII is {ascii2}",
             character1 = c,
             ascii1 = c as i32,
             character2 = f,
             ascii2 = f as i32);
}
