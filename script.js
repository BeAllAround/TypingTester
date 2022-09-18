function typer(text) {
        let speed = document.querySelector("#speed");
	let accuracy = document.querySelector("#accuracy");
	let canvas = document.querySelector("#canvas");

	text = text.split(' ').filter(v=>v!=='').join(' ') // white-space hack

	let checker = true;
	let output = "";
	let list = []
	let c = 0; // character counter
	let start, _final;
	let c1 = 0;
	let acc = 100;
	let words


        if(!c1){start = (new Date()).getTime(); c1 = 1;};
        reFRESH(text, list, canvas);
        document.addEventListener('keypress', logKey);

	const interlude = setInterval(()=>{
        	_final = ((new Date()).getTime() - start);
        	speed.textContent = (wps(output.length, _final/1000)).toString();
        	accuracy.textContent = FormatAcc(acc);
	}, 200);

    	function clear(){
        	clearInterval(interlude);
        	// document.dispatchEvent; // in the works;
        	canvas.textContent = "DONE!";
        	speed.textContent = (wps(output.length, _final/1000)).toString();
        	accuracy.textContent = FormatAcc(acc);
    	}

function simpleSpan(content) {
	let elem = document.createElement('span')
	elem.textContent = content
	return elem
}

function reFRESH(_text, list, elem){
	console.log('_text: ', words = _text.split(' ').filter(v=>v!=='').map((v,i)=>[i,v]))
	for(let i = 0; i<words.length; i++){
		let e;
		e = document.createElement('div');
		e.id = 'word' + words[i][0]
		Object.assign(e.style, {display: 'inline',})
		for(let word of words[i][1]) {
			e.appendChild(simpleSpan(word))
		}
		e.appendChild(simpleSpan(' '))
		list.push(e);
	}

	console.log('elem: ', elem)
	console.log('list: ', list)
	for(let i = 0; i<list.length; i++){
		elem.appendChild(list[i]);
	}
	setUpAccuracy(accuracy);
}

function FormatAcc(s){
	return "ACCURACY: " + s.toString() + "%";
}

function setUpAccuracy(elem){
	elem.textContent = FormatAcc(acc);
};

function innerHtmlGenerator(list){ // superfluous
	let _string = "";
	for(let i = 0; i<list.length; i++){
		_string+=list[i].innerHTML;
	}
	return _string;
};



function wps(length, secondsPassed){ // f(value);
	return (length*60)/(5*secondsPassed);
}

let C = 0
function logKey(e){
if(checker) {
	let key = e.key, b, word, ch
	word = list[C] // current word
	console.log('current word: ', word)

	Object.assign(word.style, {'background-color': 'green',})

	if(word.children[c].textContent == key) {
		output += String(e.key); // for the calculation
		ch = word.children[c++]
		ch.style.background = 'blue'
		if(word.children.length == c) {
			c = 0 // reset couter for the next word
			C++ // next word
		}
	}else{ // else  diminish the accuracy;
		acc -= 0.3;
	}

	if(text == output) {
                clear()
                checker = false
                return
        }

    }
}

}

let text = "Let's see how fast you can type, shall we?";
new typer(text)
