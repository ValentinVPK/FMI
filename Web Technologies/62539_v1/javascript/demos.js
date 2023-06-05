// демо 1

const json = '{"result":true, "count":42}';
const obj = JSON.parse(json);

console.log(obj.count);
// Очакван резултат: 42

console.log(obj.result);
// Очакван резултат: true

//демо 2

JSON.parse("{}"); // {}
JSON.parse("true"); // true
JSON.parse('"foo"'); // "foo"
JSON.parse('[1, 5, "false"]'); // [1, 5, "false"]
JSON.parse("null"); // null

// демо 3

JSON.parse(
    '{"p": 5}',
    (key, value) =>
      typeof value === "number"
        ? value * 2 // връща value * 2 за числата
        : value, // връща всичко останало без да го променя
);

// { p: 10 }
  
JSON.parse('{"1": 1, "2": 2, "3": {"4": 4, "5": {"6": 6}}}', (key, value) => {
  console.log(key);
  return value;
});
// 1
// 2
// 4
// 6
// 5
// 3
// ""

  // демо 4

// и двете ще хвърлят SyntaxError
JSON.parse("[1, 2, 3, 4, ]");
JSON.parse('{"foo" : 1, }');


// демо 5

// ще хвърли SyntaxError
JSON.parse("{'foo': 1}");


//демо 6

console.log(JSON.stringify({ x: 5, y: 6 }));
// Очакван резултат: "{"x":5,"y":6}"

console.log(JSON.stringify([new Number(3), new String('false'), new Boolean(false)]));
// Очакван резултат: "[3,"false",false]"

console.log(JSON.stringify({ x: [10, undefined, function(){}, Symbol('')] }));
// Очакван резултат: "{"x":[10,null,null,null]}"

console.log(JSON.stringify(new Date(2006, 0, 2, 15, 4, 5)));
// Очакван резултат: ""2006-01-02T15:04:05.000Z""

//демо 7

function replacer(key, value) {
    // Филтриране на свойства
    if (typeof value === "string") {
      return undefined;
    }
    return value;
}
  
const foo1 = {
  foundation: "Mozilla",
  model: "box",
  week: 45,
  transport: "car",
  month: 7,
};
JSON.stringify(foo, replacer);
// '{"week":45,"month":7}'


// демо 8

const foo2 = {
    foundation: "Mozilla",
    model: "box",
    week: 45,
    transport: "car",
    month: 7,
};
  
JSON.stringify(foo, ["week", "month"]);
// '{"week":45,"month":7}', запазваме само "week" и "month" свойствата


// демо 9

console.log(JSON.stringify({ uno: 1, dos: 2 }, null, "\t"));
/*
{
    "uno": 1,
    "dos": 2
}
*/

//демо 10

const circularReference = {};
circularReference.myself = circularReference;

// Сериализирането на циклична референция хвърля "TypeError: cyclic object value"
JSON.stringify(circularReference);

//демо 11

callbackName({
    "firstName": "Maciej",
    "lastName": "Cieslar"
})

//демо 12
let jsonpID = 0;

function jsonp(url, timeout = 7500) {
  const head = document.querySelector('head');
  jsonpID += 1;

  return new Promise((resolve, reject) => {
    let script = document.createElement('script');
    const callbackName = `jsonpCallback${jsonpID}`;

    script.src = encodeURI(`${url}?callback=${callbackName}`);
    script.async = true;

    const timeoutId = window.setTimeout(() => {
      cleanUp();

      return reject(new Error('Timeout'));
    }, timeout);

    window[callbackName] = data => {
      cleanUp();

      return resolve(data);
    };

    script.addEventListener('error', error => {
      cleanUp();

      return reject(error);
    });

    function cleanUp() {
      window[callbackName] = undefined;
      head.removeChild(script);
      window.clearTimeout(timeoutId);
      script = null;
    }


    head.appendChild(script);
  });
}

// демо 13

const timeoutId = window.setTimeout(() => {
  cleanUp();

  return reject(new Error('Timeout'));
}, timeout);

window[callbackName] = data => {
  cleanUp();

  return resolve(data);
};

script.addEventListener('error', error => {
  cleanUp();

  return reject(error);
});
    

// демо 14

function cleanUp() {
    window[callbackName] = undefined;
    head.removeChild(script);
    window.clearTimeout(timeoutId);
    script = null;
}


// демо 15

jsonp('https://gist.github.com/maciejcieslar/1c1f79d5778af4c2ee17927de769cea3.json')
 .then(console.log)
 .catch(console.error);
jsonp('https://gist.github.com/maciejcieslar/1c1f79d5778af4c2ee17927de769cea3.json')
 .then(console.log)
 .catch(console.error);
