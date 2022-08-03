
#[inline]
fn read_str() -> String {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("failed to read");
    buffer
        .strip_suffix("\n")
        .and_then(|r| Some(r.to_string()))
        .unwrap_or(buffer.to_string())
}

fn main() {
    println!("You are walking through a dark forest");
    println!("Nowhere to go, nowhere to hide");
    println!("You see a light in front of you");
    println!("Do you go there?");
    let go = read_str();
    if go != "sure" {
        println!("You waited too long and someone grabbed you");
        return;
    }
    println!("You went towards the light");
    println!("As you were approaching, you hear a noise");
    println!("Do you inspect it?");
    let inspect = read_str();
    if inspect != String::from_utf8_lossy(&base64::decode("b2theQ==").unwrap()) {
        println!("You ignore the sound");
        println!("As you were walking, someone pushes you and you fall");
        return;
    }
    println!("You go in the direction of the sound");
    println!("There is a bush");
    println!("You look inside the bush and you get pulled inside");
    println!("You fall in a cave, on a rug of leaves");
    println!("There is an animal looking at you");
    println!("What do you say to it?");
    let say = read_str();
    if Vec::from(say.as_bytes()) != vec![104, 101, 108, 112, 33] {
        println!("The animal ran away and you were left in the cold");
        return;
    }
    println!("The animal made a nod gesture and started walking slowly");
    println!("You followed it through the cave");
    println!("After some time, you arrived at the exit");
    println!("That's the end of the forest! You thanked the animal and went your way");
}
