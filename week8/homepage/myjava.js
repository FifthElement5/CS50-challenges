var quotes = [
    'Fishing is much more than fish. It is the great occasion when we may return to the fine simplicity of our forefathers. - Herbert Hoover',
    'If people concentrated on the really important things in life, there’d by a shortage of fishing poles. -  Doug Larson',
    'There’s a fine line between fishing and standing on the shore like an idiot. - Steven Wright',
    'Fishing is a hard job. Fishing at night. Rain. Day, night… You have to be wise and smart. And quick. - Mariano Rivera',
    'Fishing provides that connection with the whole living world. It gives you the opportunity of being totally immersed, turning back into yourself in a good way. A form of meditation, some form of communion with levels of yourself that are deeper than the ordinary self. - Ted Hughes',
    'Many men go fishing all of their lives without knowing that it is not fish they are after. - Henry David Thoreau',
    'The charm of fishing is that it is the pursuit of what is elusive but attainable, a perpetual series of occasions of hope. - John Buchan',
    'There are always new places to go fishing. For any fisherman, there’s always a new place, always a new horizon. - Jack Nicklaus',
    'Dear Lord, grant me a serenity to accept the size of the fish, the courage not to lie about it,and the wisdom to know that none of my fishing buddies would believe me anyway...Amen - Anonim'
]
var fontType = "courier";

for (var i = 0; i < quotes.length; i++) {
    var quoteWords = quotes[i].split(' ');
    var lastWord = quoteWords.length - 1;
    var secondLastWord = quoteWords.length - 2;

    //modify the last two words
    quoteWords[lastWord] = '<span style="font-family:' + fontType + ';">' + quoteWords[lastWord] + '</span>';
    quoteWords[secondLastWord] ='<br><br><span style="font-family:' + fontType + '; text-align: center;">' + quoteWords[secondLastWord] + '</span>';

    quotes[i] = quoteWords.join(' ');
}

function newQuote() {
 var randomNumber = Math.floor(Math.random() * (quotes.length));
 document.getElementById('quoteDisplay').innerHTML = quotes[randomNumber];
}

document.addEventListener('DOMContentLoaded', function() {
    var quoteDisplay = document.getElementById('quoteDisplay');
    if (quoteDisplay) {
      newQuote();
    }
  });


  //run script once DOM is loaded
  document.addEventListener('DOMContentLoaded', function() {

  //change color to green

  let count = 0;

  let correct = document.querySelectorAll('.correct');
  for (let j=0; j <correct.length; j++) {
  correct[j].addEventListener('click', function() {

      document.querySelector('#feedback').innerHTML = 'Correct! Please proceed to the next question!';
      document.querySelector('#feedback').style.backgroundColor = 'rgba(0, 255, 94, 0.6)';

      count++;
      //chanage color when all questions are answered
          if (count >= 6) {
              document.querySelector('#feedback').innerHTML = 'Congratulations You are a fish expert.';
              document.querySelector('#feedback').style.backgroundColor = 'rgba(0, 55, 255, 0.6)';
              document.querySelector('#feedback').style.height = '25%';
              count = 0;
          }

  });
  }
  //change color for red when wrong answer
  let incorrect = document.querySelectorAll('.incorrect');
  for (let i=0; i < incorrect.length; i++) {
      incorrect[i].addEventListener('click', function() {
          document.querySelector('#feedback').innerHTML = 'Incorrect! Try Again';
          document.querySelector('#feedback').style.backgroundColor = 'rgba(255, 0, 34, 0.6)';


      });
  }

  let reset = document.querySelector('.reset');
  reset.addEventListener('click', function() {
      document.querySelector('#feedback').innerHTML = '';
      document.querySelector('#feedback').style.backgroundColor = '#006666';
      document.querySelector('#feedback').style.height = '2rem';
      count = 0;
  });


  });

