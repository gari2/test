The following content is provided
under a Creative Commons license.
00:04
Your support will help MIT OpenCourseWare continue
00:06
to offer high quality educational resources for free.
00:10
To make a donation or view additional materials
00:13
from hundreds of MIT courses, visit MIT OpenCourseWare
00:17
at ocw.mit.edu.
00:21
PROFESSOR: We're going to start a brand new, exciting topic,
00:23
dynamic programming.
00:25
AUDIENCE: Yes!
00:25
PROFESSOR: Yeah!
00:26
So exciting.
00:28
Actually, I am really excited because dynamic programming
00:30
is my favorite thing in the world, in algorithms.
00:33
And it's going to be the next four lectures,
00:37
it's so exciting.
00:38
It has lots of different facets.
00:40
It's a very general, powerful design technique.
00:44
We don't talk a lot about algorithm design in this class,
00:47
but dynamic programming is one that's so important.
00:50
And also takes a little while to settle in.
00:52
We like to injected it into you now, in 006.
00:57
So in general, our motivation is designing new algorithms
01:05
and dynamic programming, also called DP,
01:10
is a great way-- or a very general, powerful way
01:17
to do this.
01:33
It's especially good, and intended for, optimization
01:37
problems, things like shortest paths.
01:39
You want to find the best way to do something.
01:41
Shortest path is you want to find the shortest
01:43
path, the minimum-length path.
01:46
You want to minimize, maximize something, that's
01:48
an optimization problem, and typically
01:51
good algorithms to solve them involve dynamic programming.
01:54
It's a bit of a broad statement.
01:56
You can also think of dynamic programming
01:58
as a kind of exhaustive search.
02:01
Which is usually a bad thing to do
02:03
because it leads to exponential time.
02:05
But if you do it in a clever way, via dynamic programming,
02:09
you typically get polynomial time.
02:13
So one perspective is that dynamic programming
02:17
is approximately careful brute force.
02:23
It's kind of a funny combination.
02:25
A bit of an oxymoron.
02:29
But we take the idea of brute force, which is,
02:31
try all possibilities and you do it carefully
02:35
and you get it to polynomial time.
02:37
There are a lot of problems where essentially
02:38
the only known polynomial time algorithm is
02:41
via dynamic programming.
02:42
It doesn't always work, there's some problems
02:44
where we don't think there are polynomial time algorithms,
02:46
but when it's possible DP is a nice, sort of,
02:50
general approach to it.
02:54
And we're going to be talking a lot about dynamic programming.
02:56
There's a lot of different ways to think about it.
02:59
We'll look at a few today.
03:02
We're going to warm up today with some fairly easy problems
03:05
that we already know how to solve,
03:07
namely computing Fibonacci numbers.
03:09
It's pretty easy.
03:11
And computing shortest paths.
03:13
And then in the next three lectures
03:14
we're going to get to more interesting examples
03:16
where it's pretty surprising that you can even
03:20
solve the problem in polynomial time.
03:24
Probably the first burning question on your mind,
03:26
though, is why is it called dynamic programming?
03:29
What does that even mean?
03:31
And I used to have this spiel about, well, you
03:34
know, programming refers to the-- I think
03:37
it's the British notion of the word,
03:39
where it's about optimization.
03:42
Optimization in American English is something
03:44
like programming in British English,
03:47
where you want to set up the program--
03:50
the schedule for your trains or something,
03:52
where programming comes from originally.
03:54
But I looked up the actual history of,
03:57
why is it called dynamic programming.
04:00
Dynamic programming was invented by a guy named Richard Bellman.
04:04
You may have heard of Bellman in the Bellman-Ford algorithm.
04:07
So this is actually the precursor to Bellman-Ford.
04:10
And we're going to see Bellman-Ford come up naturally
04:13
in this setting.
04:15
So here's a quote about him.
04:17
It says, Bellman explained that he
04:19
invented the name dynamic programming to hide the fact
04:22
that he was doing mathematical research.
04:25
He was working at this place called Rand,
04:27
and under a secretary of defense who had a pathological fear
04:31
and hatred for the term research.
04:35
So he settled on the term dynamic programming
04:36
because it would be difficult to give
04:39
a pejorative meaning to it.
04:42
And because it was something not even
04:43
a congressman could object to.
04:45
Basically, it sounded cool.
04:49
So that's the origin of the name dynamic programming.
04:52
So why is the called that?
04:53
Who knows.
04:55
I mean, now you know.
04:56
But it's not-- it's a weird term.
04:59
Just take it for what it is.
05:04
It may make some kind of sense, but--
05:06
All right.
05:07
So we are going to start with this example of how
05:14
to compute Fibonacci numbers.
05:16
And maybe before we actually start
05:18
I'm going to give you a sneak peak of what
05:23
you can think of dynamic programming as.
05:26
And this equation, so to speak, is
05:37
going to change throughout today's lecture.
05:42
In the end we'll settle on a sort
05:43
of more accurate perspective.
05:46
The basic idea of dynamic programming
05:49
is to take a problem, split it into subproblems,
05:53
solve those subproblems, and reuse the solutions
05:55
to your subproblems.
05:56
It's like a lesson in recycling.
05:59
So we'll see that in Fibonacci numbers.
06:03
So you remember Fibonacci numbers, right?
06:06
The number of rabbits you have on day n, if they reproduce.
06:15
We've mentioned them before, we're talking about AVL trees,
06:18
I think.
06:19
So this is the usual-- you can think
06:23
of it as a recursive definition or recurrence on Fibonacci
06:26
numbers.
06:27
It's the definition of what the nth Fibonacci number is.
06:30
So let's suppose our goal-- an algorithmic problem is,
06:34
compute the nth Fibonacci number.
06:39
And I'm going to assume here that that fits in a word.
06:42
And so basic arithmetic, addition,
06:44
whatever's constant time per operation.
06:48
So how do we do it?
06:50
You all know how to do it.
06:52
Anyways-- but I'm going to give you the dynamic programming
06:56
perspective on things.
06:57
So this will seem kind of obvious,
07:00
but it is-- we're going to apply exactly the same principles
07:03
that we will apply over and over in dynamic programming.
07:06
But here it's in a very familiar setting.
07:11
So we're going to start with the naive recursive algorithm.
07:24
And that is, if you want to compute the nth Fibonacci
07:29
number, you check whether you're in the base case.
07:35
I'm going to write it this way.
07:55
So f is just our return value.
07:57
You'll see why I write it this way in a moment.
07:59
Then you return f.
08:01
In the base case it's 1, otherwise
08:03
you recursively call Fibonacci of n minus 1.
08:05
You recursively call Fibonacci of n minus 2.
08:08
Add them together, return that.
08:10
This is a correct algorithm.
08:12
Is it a good algorithm?
08:15
No.
08:16
It's very bad.
08:17
Exponential time.
08:23
How do we know it's exponential time,
08:25
other than from experience?
08:27
Well, we can write the running time as recurrence.
08:31
T of n represents the time to compute the nth Fibonacci
08:34
number.
08:35
How can I write the recurrence?
08:39
You're gonna throwback to the early lectures, divide
08:41
and conquer.
08:48
I hear whispers.
08:50
Yeah?
08:51
AUDIENCE: [INAUDIBLE].
08:55
PROFESSOR: Yeah.
08:57
T of n minus 1 plus t of n minus 2 plus constant.
09:07
I don't know how many you have by now.
09:11
So to create the nth Fibonacci number
09:13
we have to compute the n minus first Fibonacci number,
09:15
and the n minus second Fibonacci number.
09:17
That's these two recursions.
09:19
And then we take constant time otherwise.
09:21
We do constant number of additions, comparisons.
09:24
Return all these operations-- take constant time.
09:27
So that's a recurrence.
09:29
How do we solve this recurrence?
09:31
Well one way is to see this is the Fibonacci recurrence.
09:35
So it's the same thing.
09:37
There's this plus whatever.
09:38
But in particular, this is at least the nth Fibonacci number.
09:41
And if you know Fibonacci stuff, that's
09:43
about the golden ratio to the nth power.
09:48
Which is bad.
09:50
We had a similar recurrence in AVL trees.
09:52
And so another way to solve it-- it's
09:55
just good review-- say, oh well, that's
09:59
at least 2 times t of n minus 2.
10:03
Because it's going to be monotone.
10:05
The bigger n is, the more work you have to do.
10:07
Because to do the nth thing you have
10:08
to do the n minus first thing.
10:10
So we could just reduce t of n minus 1 to t of n minus 2.
10:14
That will give us a lower bound.
10:16
And now these two terms-- now this is sort of an easy thing.
10:19
You see that you're multiplying by 2 each time.
10:22
You're subtracting 2 from n each time.
10:24
How many times can I subtract 2 from n?
10:27
N/2 times, before I get down to a constant.
10:30
And so this is equal to 2 to the n over 2--
10:37
I mean, times some constant, which
10:39
is what you get in the base case.
10:41
So I guess I should say theta.
10:45
This thing is theta that.
10:48
OK.
10:49
So it's at least that big.
10:51
And the right constant is phi.
10:56
And the base of the exponent.
10:58
OK.
10:59
So that's a bad algorithm.
11:00
We all know it's a bad algorithm.
11:03
But I'm going to give you a general approach for making
11:06
bad algorithms like this good.
11:09
And that general approach is called memoization.
11:14
We'll go over here.
11:19
And this is a technique of dynamic programming.
11:24
So I'm going to call this the memoized dynamic programming
11:28
algorithm.
11:36
So did I settle on using memo in the notes?
11:44
Yeah.
11:48
The idea is simple.
11:50
Whenever we compute a Fibonacci number
11:52
we put it in a dictionary.
11:55
And then when we need to compute the nth Fibonacci
11:57
number we check, is it already in the dictionary?
11:58
Did we already solve this problem?
12:00
If so, return that answer.
12:03
Otherwise, computer it.
12:05
You'll see the transformation is very simple.
12:57
OK.
12:59
These two lines are identical to these two lines.
13:04
So you can see how the transformation
13:06
works in general.
13:07
You could do this with any recursive algorithm.
13:10
The memoization transformation on that algorithm--
13:14
which is, we initially make an empty dictionary called memo.
13:19
And before we actually do the computation we say,
13:22
well, check whether this version of the Fibonacci problem,
13:26
computing f of n, is already in our dictionary.
13:31
So if that key is already in the dictionary,
13:33
we return the corresponding value in the dictionary.
13:38
And then once we've computed the nth Fibonacci number,
13:41
if we bothered to do this, if this didn't apply,
13:44
then we store it in the memo table.
13:47
So we say well, if you ever need to compute f of n again,
13:50
here it is.
13:52
And then we return that value.
13:54
So this is a general procedure.
13:57
It can apply to any recursive algorithm
14:00
with no side effects I guess, technically.
14:04
And it turns out, this makes the algorithm efficient.
14:07
Now there's a lot of ways to see why it's efficient.
14:12
In general, maybe it's helpful to think about the recursion
14:15
tree.
14:16
So if you want to compute fn in the old algorithm,
14:19
we compute fn minus 1 and fn minus two
14:22
completely separately.
14:23
To compute fn minus 1 we compute fn minus 2 and fn minus 3.
14:29
To compute fn minus 2 we compute fn minus 3 and fn minus 4.
14:34
And so on.
14:35
And you can see why that's exponential in n.
14:39
Because we're only decrementing n by one or two each time.
14:44
But then you observe, hey, these fn minus 3's are the same.
14:48
I should really only have to compute them once.
14:50
And that's what we're doing here.
14:52
The first time you call fn minus 3, you do work.
14:55
But once it's done and you go over to this other recursive
14:58
call, this will just get cut off.
15:00
There's no tree here.
15:02
Here we might have some recursive calling.
15:04
Here we won't, because it's already in the memo table.
15:08
In fact, this already happens with fn minus 2.
15:11
This whole tree disappears because fn minus 2
15:15
has already been done.
15:17
OK.
15:18
So it's clear why it improves things.
15:21
So in fact you can argue that this call will be free
15:24
because you already did the work in here.
15:27
But I want to give you a very particular way of thinking
15:30
about why this is efficient, which is following.
16:06
So you could write down a recurrence for the running time
16:09
here.
16:10
But in some sense recurrences aren't quite the right way
16:13
of thinking about this because recursion
16:15
is kind of a rare thing.
16:17
If you're calling Fibonacci of some value, k,
16:20
you're only going to make recursive calls the first time
16:23
you call Fibonacci of k.
16:24
Because henceforth, you've put it
16:28
in the memo table you will not recurse.
16:30
So you can think of there being two versions
16:35
of calling Fibonacci of k.
16:36
There's the first time, which is the non-memoized version that
16:40
does recursion-- does some work.
16:42
And then every time henceforth you're
16:46
doing memoized calls of Fibonacci of k,
16:48
and those cost constant time.
16:51
So the memoized calls cost constant time.
16:59
So we can think of them as basically free.
17:03
That's when you call Fibonacci of n minus 2,
17:06
because that's a memoized call, you really
17:09
don't pay anything for it.
17:10
I mean, you're already paying constant time
17:12
to do addition and whatever.
17:14
So you don't have to worry about the time.
17:16
There's no recursion here.
17:18
And then what we care about is that the number
17:21
of non-memorized calls, which is the first time you
17:26
call Fibonacci of k, is n.
17:33
No theta is even necessary.
17:35
We are going to call Fibonacci of 1.
17:38
At some point we're going to call Fibonacci of 2
17:41
at some point, and the original call is Fibonacci of n.
17:46
All of those things will be called at some point.
17:48
That's pretty easy to see.
17:49
But in particular, certainly at most this,
17:52
we never call Fibonacci of n plus 1
17:53
to compute Fibonacci of n.
17:55
So it's at most n calls.
17:57
Indeed it will be exactly n calls that are not memoized.
18:00
Those ones we have to pay for.
18:02
How much do we have to pay?
18:03
Well, if you don't count the recursion-- which
18:07
is what this recurrence does-- if you ignore
18:09
recursion then the total amount of work done here is constant.
18:16
So I will say the non-recursive work per call is constant.
18:30
And therefore I claim that the running time is
18:34
constant-- I'm sorry, is linear.
18:37
Constant would be pretty amazing.
18:41
This is actually not the best algorithm-- as an aside.
18:44
The best algorithm for computing the nth Fibonacci number
18:46
uses log n arithmetic operations.
18:50
So you can do better, but if you want
18:51
to see that you should take 6046.
18:55
OK.
18:55
We're just going to get to linear today, which
18:57
is a lot better than exponential.
19:01
So why linear?
19:03
Because there's n non-memoize calls, and each of them
19:07
cost constant.
19:08
So it's the product of those two numbers.
19:12
This is an important idea.
19:14
And it's so important I'm going to write it
19:18
down again in a slightly more general framework.
19:25
In general, in dynamic programming--
19:37
I didn't say why it's called memoization.
19:40
The idea is you have this memo pad where
19:42
you write down all your scratch work.
19:44
That's this memo dictionary.
19:46
And to memoize is to write down on your memo pad.
19:49
I didn't make it up.
19:50
Another crazy term.
19:52
It means remember.
19:55
And then you remember all the solutions that you've done.
19:59
And then you reuse those solutions.
20:02
Now these solutions are not really a solution
20:04
to the problem that I care about.
20:06
The problem I care about is computing the nth Fibonacci
20:08
number.
20:09
To get there I had to compute other Fibonacci numbers.
20:13
Why?
20:15
Because I had a recursive formulation.
20:16
This is not always the way to solve a problem.
20:19
But usually when you're solving something
20:22
you can split it into parts, into subproblems, we call them.
20:28
They're not always of the same flavor
20:29
as your original goal problem, but there's
20:31
some kind of related parts.
20:34
And this is the big challenge in designing a dynamic program,
20:38
is to figure out what are the subproblems.
20:41
Let's say, the first thing I want
20:43
to know about a dynamic program, is what are the subproblems.
20:47
Somehow they are designed to help solve your actual problem.
20:58
And the idea of memoization is, once you solve a subproblem,
21:01
write down the answer.
21:02
If you ever need to solve that same problem again
21:05
you reuse the answer.
21:07
So that is the core idea.
21:09
And so in this sense dynamic programming
21:10
is essentially recursion plus memoization.
21:23
And so in this case these are the subproblems.
21:27
Fibonacci of 1 through Fibonacci of n.
21:29
The one we care about is Fibonacci of n.
21:31
But to get there we solve these other subproblems.
21:36
In all cases, if this is the situation-- so
21:40
for any dynamic program, the running time
21:43
is going to be equal to the number of different subproblems
21:46
you might have to solve, or that you do solve,
21:50
times the amount of time you spend per subproblem.
22:00
OK.
22:01
In this situation we had n subproblems.
22:06
And for each of them we spent constant time.
22:10
And when I measure the time per subproblem
22:13
which, in the Fibonacci case I claim is constant,
22:15
I ignore recursive calls.
22:18
That's the key.
22:19
We don't have to solve recurrences
22:21
with dynamic programming.
22:22
Yay.
22:23
No recurrences necessary.
22:25
OK.
22:25
Don't count recursions.
22:34
Obviously, don't count memoized recursions.
22:36
The reason is, I only need to count them once.
22:39
After the first time I do it, it's free.
22:42
So I count how many different subproblems do I need to do?
22:45
These are they going to be the expensive recursions where
22:48
I do work, I do some amount of work,
22:49
but I don't count the recursions because otherwise I'd
22:52
be double counting.
22:53
I only want to count each subproblem once,
22:56
and then this will solve it.
22:59
So a simple idea.
23:00
In general, dynamic programming is a super simple idea.
23:03
It's nothing fancy.
23:05
It's basically just memoization.
23:07
There is one extra trick we're going to pull out,
23:10
but that's the idea.
23:12
All right.
23:14
Let me tell you another perspective.
23:24
This is the one maybe most commonly taught.
23:28
Is to think of-- but I'm not a particular fan of it.
23:31
I really like memoization.
23:32
I think it's a simple idea.
23:35
And as long as you remember this formula here,
23:38
it's really easy to work with.
23:43
But some people like to think of it this way.
23:45
And so you can pick whichever way you find most intuitive.
23:49
Instead of thinking of a recursive algorithm, which
23:51
in some sense starts at the top of what you want to solve
23:55
and works its way down, you could do the reverse.
23:58
You could start at the bottom and work your way up.
24:00
And this is probably how you normally
24:02
think about computing Fibonacci numbers
24:03
or how you learned it before.
24:05
I'm going to write it in a slightly funny way.
24:31
The point I want to make is that the transformation
24:33
I'm doing from the naive recursive algorithm,
24:38
to the memoized algorithm, to the bottom-up algorithm
24:42
is completely automated.
24:44
I'm not thinking, I'm just doing.
24:46
OK.
24:47
It's easy.
24:49
This code is exactly the same as this code
24:52
and as that code, except I replaced n by k.
24:56
Just because I needed a couple of different n values here.
24:59
Or I want to iterate over n values.
25:04
And then there's this stuff around that code
25:06
which is just formulaic.
25:11
A little bit of thought goes into this for loop,
25:13
but that's it.
25:15
OK.
25:15
This does exactly the same thing as the memoized algorithm.
25:22
Maybe it takes a little bit of thinking
25:24
to realize, if you unroll all the recursion that's happening
25:26
here and just write it out sequentially,
25:29
this is exactly what's happening.
25:31
This code does exactly the same additions, exactly
25:34
the same computations as this.
25:37
The only difference is how you get there.
25:39
Here we're using a loop, here we're using recursion.
25:42
But the same things happen in the same order.
25:45
It's really no difference between the code.
25:47
This code's probably going to be more efficient practice
25:49
because you don't make function calls so much.
25:52
In fact I made a little mistake here.
25:55
This is not a function call, it's
25:57
just a lookup into a table.
25:59
Here I'm using a hash table to be simple,
26:01
but of course you could use an array.
26:05
But they're both constant time with good hashing.
26:10
All right.
26:10
So is it clear what this is doing?
26:12
I think so.
26:13
I think I made a little typo.
26:16
So we have to compute-- oh, another typo.
26:21
We have to compute f1 up to fn, which in python is that.
26:27
And we compute it exactly how we used to.
26:31
Except now, instead of recursing,
26:34
I know that when I'm computing the k Fibonacci number-- man.
26:38
So many typos.
26:39
AUDIENCE: [LAUGHTER]
26:40
PROFESSOR: You guys are laughing.
26:42
When I compute the kth Fibonacci number
26:45
I know that I've already computed the previous two.
26:48
Why?
26:48
Because I'm doing them in increasing order.
26:50
Nothing fancy.
26:52
Then I can just do this and the solutions
26:55
will just be waiting there.
26:56
If they work, I'd get a key error.
26:58
So I'd know that there's a bug.
27:00
But in fact, I won't get a key error.
27:01
I will have always computed these things already.
27:05
Then I store it in my table.
27:06
Then I iterate.
27:07
Eventually I've solved all the subproblems, f1 through fn.
27:11
And the one I cared about was the nth one.
27:14
OK.
27:14
So straightforward.
27:17
I do this because I don't really want
27:19
to have to go through this transformation
27:21
for every single problem we do.
27:22
I'm doing it in Fibonacci because it's super easy
27:25
to write the code out explicitly.
27:27
But you can do it for all of the dynamic programs
27:29
that we cover in the next four lectures.
27:33
OK.
27:33
I'm going to give you now the general case.
27:35
This was the special Fibonacci version.
27:39
In general, the bottom-up does exactly the same computation
27:44
as the memoized version.
27:51
And what we're doing is actually a topological sort
27:59
of the subproblem dependency DAG.
28:13
So in this case, the dependency DAG is very simple.
28:17
In order to compute-- I'll do it backwards.
28:21
In order to compute fn, I need to know fn minus 1
28:26
and fn minus 2.
28:28
If I know those I can compute fn.
28:32
Then there's fn minus 3, which is
28:35
necessary to compute this one, and that one, and so on.
28:38
So you see what this DAG looks like.
28:40
Now, I've drawn it conveniently so
28:42
all the edges go left to right.
28:43
So this is a topological order from left to right.
28:46
And so I just need to do f1, f2, up to fn in order.
28:50
Usually it's totally obvious what order
28:53
to solve the subproblems in.
28:55
But in general, what you should have in mind
28:58
is that we are doing a topological sort.
29:00
Here we just did it in our heads because it's so easy.
29:03
And usually it's so easy.
29:04
It's just a for loop.
29:05
Nothing fancy.
29:09
All right.
29:13
I'm missing an arrow.
29:20
All right.
29:22
Let's do something a little more interesting, shall we?
29:37
All right.
29:38
One thing you can do from this bottom-up perspective
29:41
is you can save space.
29:46
Storage space in the algorithm.
29:48
We don't usually worry about space in this class,
29:51
but it matters in reality.
29:55
So here we're building a table size,
29:57
n, but in fact we really only need
29:59
to remember the last two values.
30:02
So you could just store the last two values,
30:04
and each time you make a new one delete the oldest.
30:07
so by thinking a little bit here you
30:10
realize you only need constant space.
30:12
Still linear time, but constant space.
30:15
And that's often the case.
30:17
From the bottom-up perspective you
30:18
see what you really need to store,
30:20
what you need to keep track of.
30:24
All right.
30:26
I guess another nice thing about this perspective
30:28
is, the running time is totally obvious.
30:30
This is clearly constant time.
30:32
So this is clearly linear time.
30:34
Whereas, in this memoized algorithm
30:37
you have to think about, when's it
30:40
going to be memoized, when is it not?
30:42
I still like this perspective because, with this rule,
30:44
just multiply a number of subproblems
30:46
by time per subproblem, you get the answer.
30:49
But it's a little less obvious than code like this.
30:54
So choose however you like to think about it.
31:00
All right.
31:00
We move onto shortest paths.
31:28
So I'm again, as usual, thinking about single-source shortest
31:32
paths.
31:33
So we want to compute the shortest pathway from s
31:37
to v for all v. OK.
31:41
I'd like to write this initially as a naive recursive algorithm,
31:46
which I can then memoize, which I can then bottom-upify.
31:49
I just made that up.
31:53
So how could I write this as a naive recursive algorithm?
31:57
It's not so obvious.
31:59
But first I'm going to tell you how, just as an oracle tells
32:06
you, here's what you should do.
32:08
But then we're going to think about-- go back, step back.
32:10
Actually, it's up to you.
32:11
I could tell you the answer and then
32:13
we could figure out how we got there,
32:15
or we could just figure out the answer.
32:18
Preferences?
32:22
Figure it out.
32:22
All right.
32:23
Good.
32:24
No divine inspiration allowed.
32:26
So let me give you a tool.
32:37
The tool is guessing.
32:42
This may sound silly, but it's a very powerful tool.
32:48
The general idea is, suppose you don't know something
32:51
but you'd like to know it.
32:53
So what's the answer to this question?
32:55
I don't know.
32:56
Man, I really want a cushion.
32:57
How am I going to answer the question?
32:59
Guess.
33:00
OK?
33:00
AUDIENCE: [LAUGHTER]
33:02
PROFESSOR: It's a tried and tested method
33:04
for solving any problem.
33:16
I'm kind of belaboring the point here.
33:19
The algorithmic concept is, don't just try any guess.
33:23
Try them all.
33:25
OK?
33:26
AUDIENCE: [LAUGHTER]
33:29
PROFESSOR: Also pretty simple.
33:30
I said dynamic programming was simple.
33:32
OK.
33:38
Try all guesses.
33:43
This is central to the dynamic programming.
33:45
I know it sounds obvious, but if I want to fix my equation here,
33:52
dynamic programming is roughly recursion plus memoization.
33:58
This should really be, plus guessing.
34:01
Memoization, which is obvious, guessing which is obvious,
34:06
are the central concepts to dynamic programming.
34:08
I'm trying to make it sound easy because usually people
34:11
have trouble with dynamic programming.
34:12
It is easy.
34:15
Try all the guesses.
34:16
That's something a computer can do great.
34:18
This is the brute force part.
34:20
OK.
34:20
But we're going to do it carefully.
34:23
Not that carefully.
34:24
I mean, we're just trying all the guesses.
34:26
Take the best one.
34:33
That's kind of important that we can choose one
34:35
to be called best.
34:36
That's why dynamic programming is
34:38
good for optimization problems.
34:39
You want to maximize something, minimize something,
34:42
you try them all and then you can forget about all of them
34:45
and just reduce it down to one thing which
34:47
is the best one, or a best one.
34:50
OK.
34:51
So now I want you to try to apply
34:53
this principle to shortest paths.
34:56
Now I'm going to draw a picture which may help.
34:59
We have the source, s, we have some vertex,
35:08
v. We'd like to find the shortest--
35:11
a shortest path from s to v.
35:13
Suppose I want to know what this shortest path is.
35:16
Suppose this was it.
35:18
You have an idea already?
35:19
Yeah.
35:21
AUDIENCE: What you could do is you could look at everywhere
35:27
you can go from s.
35:29
[INAUDIBLE] shortest path of each of those notes.
35:33
PROFESSOR: Good.
35:33
So I can look at all the places I could go from s,
35:37
and then look at the shortest paths from there to v.
35:41
So we could call this s prime.
35:45
So here's the idea.
35:46
There's some hypothetical shortest path.
35:50
I don't know where it goes first,
35:53
so I will guess where it goes first.
35:56
I know the first edge must be one
35:58
of the outgoing edges from s.
36:00
I don't know which one.
36:01
Try them all.
36:03
Very simple idea.
36:04
Then from each of those, if somehow I
36:06
can compute the shortest path from there to v,
36:10
just do that and take the best choice
36:13
for what that first edge was.
36:15
So this would be the guess first edge approach.
36:22
It's a very good idea.
36:23
Not quite the one I wanted because unfortunately
36:28
that changes s.
36:30
And so this would work, it would just
36:32
be slightly less efficient if I'm
36:33
solving single-source shortest paths.
36:36
So I'm going to tweak that idea slightly
36:38
by guessing the last edge instead of the first edge.
36:40
They're really equivalent.
36:41
If I was doing this I'd essentially
36:43
be solving a single-target shortest paths,
36:46
which we talked about before.
36:49
So I'm going to draw the same picture.
36:56
I want to get to v. I'm going to guess the last edge,
36:59
call it uv.
37:01
I know it's one of the incoming edges to v-- unless s equals v,
37:06
then there's a special case.
37:07
As long as this path has length of at least 1,
37:09
there's some last edge.
37:11
What is it?
37:12
I don't know.
37:12
Guess.
37:14
Guess all the possible incoming edges to v, and then
37:19
recursively compute the shortest path from s to u.
37:23
And then add on the edge v.
37:25
OK.
37:26
So what is this shortest path?
37:27
It's delta of s comma u, which looks the same.
37:32
It's another subproblem that I want to solve.
37:34
There's v subproblems here I care about. .
37:37
So that's good.
37:38
I take that.
37:39
I add on the weight of the edge uv.
37:44
And that should hopefully give me delta of s comma v.
37:50
Well, if I was lucky and I guessed the right choice of u.
37:53
In reality, I'm not lucky.
37:55
So I have to minimize over all edges uv.
38:02
So this is the-- we're minimizing
38:05
over the choice of u.
38:06
V is already given here.
38:08
So I take the minimum over all edges of the shortest
38:12
path from s to u, plus the weight of the edge uv.
38:17
That should give me the shortest path because this gave me
38:19
the shortest path from s to u.
38:21
Then I added on the edge I need to get there.
38:24
And wherever the shortest path is, it uses some last edge, uv.
38:30
There's got to be some choice of u that is the right one.
38:32
That's the good guess that we're hoping for.
38:35
We don't know what the good guess
38:36
is so we just try them all.
38:38
But whatever it is, this will be the weight of that path.
38:43
It's going to take the best path from s
38:44
to u because sub paths are shortest
38:46
paths are shortest paths.
38:47
Optimal substructure.
38:48
So this part will be delta of su.
38:51
This part is obviously w of uv.
38:53
So this will give the right answer.
38:57
Hopefully.
38:59
OK.
39:00
It's certainly going to-- I mean,
39:02
this is the analog of the naive recursive algorithm
39:05
for Fibonacci.
39:05
So it's not going to be efficient if I-- I mean,
39:08
this is an algorithm, right?
39:09
You could say-- this is a recursive call.
39:13
We're going to treat this as recursive call instead
39:17
of just a definition.
39:19
Then this is a recursive algorithm.
39:23
How good or bad is this recursive algorithm?
39:27
AUDIENCE: Terrible.
39:28
PROFESSOR: Terrible.
39:28
Very good.
39:29
Very bad, I should say.
39:34
It's definitely going to be exponential
39:38
without memoization.
39:39
But we know.
39:39
We know how to make algorithms better.
39:41
We memoize.
39:42
OK.
39:43
So I think you know how to write this as a memoized algorithm.
39:46
To define the function delta of sv, you first check,
39:51
is s comma v in the memo table?
39:54
If so return that value.
39:55
Otherwise, do this computation where this is a recursive call
39:59
and then stored it in the memo table.
40:02
OK.
40:03
I don't think I need to write that down.
40:05
It's just like the memoized code over there.
40:07
Just there's now two arguments instead of one.
40:11
In fact, s isn't changing.
40:12
So I only need to store with v instead of s comma v.
40:18
Is that a good algorithm?
40:19
I claim memoization makes everything faster.
40:23
Is that a fast algorithm?
40:36
Not so obvious, I guess.
40:51
Yes?
40:52
How many people think, yes, that's a good algorithm?
40:54
AUDIENCE: Better.
40:55
PROFESSOR: Better.
40:56
Definitely better.
40:57
Can't be worse.
40:58
How many people think it's a bad algorithm still?
41:00
OK.
41:01
So three for yes, zero for no.
41:04
How many people aren't sure?
41:08
Including the yes votes?
41:09
Good.
41:12
All right.
41:13
It's not so tricky.
41:14
Let me draw you a graph.
41:27
Something like that.
41:30
So we wanted to commit delta of s comma
41:32
v. Let me give these guys names, a and b.
41:36
So we compute delta of s comma v. To compute
41:39
that we need to know delta of s comma a and delta
41:45
of s comma v. All right?
41:48
Those are the two ways-- sorry, actually we just need one.
41:51
Only one incoming edge to v. So its delta of s comma a.
42:00
Sorry-- I should have put a base case here too.
42:04
Delta of s comma s equals 0.
42:10
OK.
42:10
Delta of s comma a plus the edge.
42:12
OK.
42:13
There is some shortest path to a.
42:14
To compute the shortest path to a we
42:16
look at all the incoming edges to a.
42:18
There's only one.
42:19
So delta of s comma b.
42:22
Now I want to compute the shortest paths from b.
42:24
Well, there's two ways to get to b.
42:26
One of them is delta of s comma b-- sorry, s comma s.
42:33
Came from s.
42:35
The other way is delta of s comma v. Do you see a problem?
42:42
Yeah.
42:44
Delta of s comma v is what we were trying to figure out.
42:50
Now you might say, oh, it's OK because we're
42:51
going to memoize our answer to delta s comma v
42:54
and then we can reuse it here.
42:55
Except, we haven't finished computing delta of s
42:57
comma v. We can only put it in the memo table once we're done.
43:02
So when this call happens the memo table has not been set.
43:06
And we're going to do the same thing
43:07
over and over and over again.
43:09
This is an infinite algorithm.
43:12
Oops.
43:14
Not so hot.
43:19
So it's going to be infinite time on graphs with cycles.
43:35
OK.
43:35
For DAGs, for acyclic graphs, it actually runs in v plus e time.
43:42
This is the good case.
43:43
In this situation we can use this formula.
43:46
The time is equal to the number of subproblems
43:48
times the time per subproblem.
43:52
So I guess we have to think about that a little bit.
43:55
Where's my code?
43:55
Here's my code.
43:57
Number of subproblems is v. There's
44:00
v different subproblems that I'm using here.
44:03
I'm always reusing subproblems of the form delta
44:05
s comma something.
44:06
The something could be any of the v vertices.
44:10
How much time do I spend per subproblem?
44:14
That's a little tricky.
44:15
It's the number of incoming edges
44:17
to v. So time for a sub problem delta of sv
44:30
is the indegree of v. The number of incoming edges to v.
44:36
So this depends on v. So I can't just
44:39
take a straightforward product here.
44:41
What this is really saying is, you
44:42
should sum up over all sub problems
44:44
of the time per sub problem.
44:46
So total time is the sum over all v and v, the indegree of v.
44:58
And we know this is number of edges.
45:02
It's really-- so indegree plus 1, indegree plus 1.
45:06
So this is v plus v. OK.
45:11
Handshaking again.
45:14
OK.
45:14
Now we already knew an algorithm for shortest paths and DAGs.
45:17
And it ran a v plus e time.
45:18
So it's another way to do the same thing.
45:21
If you think about it long enough,
45:23
this algorithm memoized, is essentially
45:27
doing a depth first search to do a topological sort
45:30
to run one round of Bellman-Ford.
45:33
So we had topological sort plus one round of Bellman-Ford.
45:36
This is kind of it all rolled into one.
45:38
This should look kind of like the Bellman Ford relaxation
45:40
step, or shortest paths relaxation step.
45:42
It is.
45:44
This min is really doing the same thing.
45:46
So it's really the same algorithm.
45:48
But we come at it from a different perspective.
45:52
OK.
45:53
But I claim I can use this same approach
45:55
to solve shortest paths in general graphs, even when they
45:58
have cycles.
46:01
How am I going to do that?
46:04
DAGs seem fine-- oh, what was the lesson learned here?
46:08
Lesson learned is that subproblem dependencies
46:18
should be acyclic.
46:19
Otherwise, we get an infinite algorithm.
46:22
For memoization to work this is what you need.
46:24
It's all you need.
46:29
OK.
46:30
We've almost seen this already.
46:32
Because I said that, to do a bottom up algorithm
46:35
you do a topological sort of this subproblem dependency DAG.
46:39
I already said it should be acyclic.
46:40
OK.
46:41
We just forgot.
46:42
I didn't tell you yet.
46:43
So for that to work it better be acyclic.
46:45
For DP to work, for memoization to work, it better be acyclic.
46:48
If you're acyclic then this is the running time.
46:55
So that's all general.
46:59
OK.
47:00
So somehow I need to take a cyclic graph
47:02
and make it acyclic.
47:08
We've actually done this already in recitation.
47:18
So if I have a graph-- let's take
47:22
a very simple cyclic graph.
47:25
OK.
47:26
One thing I could do is explode it into multiple layers.
47:29
We did this on quiz two in various forms.
47:32
It's like the only cool thing you can do with shortest paths,
47:35
I feel like.
47:37
If you want to make a shortest path problem harder,
47:40
require that you reduce your graph to k copies of the graph.
47:45
I'm going to do it in a particular way
47:47
here-- which I think you've seen in recitation-- which
47:50
is to think of this axis as time, or however you want,
47:54
and make all of the edges go from each layer
47:57
to the next layer.
48:01
This should be a familiar technique.
48:03
So the idea is, every time I follow
48:05
an edge I go down to the next layer.
48:07
This makes any graph acyclic.
48:09
Done.
48:11
What in the world does this mean?
48:13
What is it doing?
48:20
What does it mean?
48:21
Double rainbow.
48:23
All right.
48:23
AUDIENCE: [LAUGHTER]
48:24
PROFESSOR: So-- I don't know how I've
48:26
gone so long in the semester without referring
48:28
to double rainbow.
48:29
It used to be my favorite.
48:30
All right.
48:31
So here's what it means.
48:34
Delta sub k of sv.
48:37
I'm going to define this first-- this
48:38
is a new kind of subproblem-- which
48:41
is, what is the shortest-- what is the weight of the shortest
48:49
s to v path that uses, at most, k edges.
48:58
So I want it to be shortest in terms of total weight,
49:00
but I also want it to use few edges total.
49:03
So this is going to be 0.
49:05
In some sense, if you look at-- so here's s
49:08
and I'm always going to make s this.
49:11
And then this is going to be v in the zero situation.
49:15
This is going to be v in the one situation,
49:17
v-- so if I look at this v, I look at the shortest
49:20
path from s to v, that is delta sub 0 of sv.
49:24
So maybe I'll call this v sub 0, v sub 1, v sub 2.
49:28
OK.
49:28
Shortest path from here to here is,
49:30
there's no way to get there on 0 edges.
49:32
Shortest path from here to here, that
49:33
is the best way to get there with, at most, one edge.
49:38
Shortest path from here to here--
49:39
well, if I add some vertical edges too,
49:41
I guess, cheating a little bit.
49:43
Then this is the best way to get from s
49:45
to v using at most two edges.
49:46
And then you get a recurrence which
49:51
is the min over all last edges.
49:54
So I'm just copying that recurrence,
49:56
but realizing that the s to u part uses one fewer edge.
50:03
And then I use the edge uv.
50:07
OK.
50:07
That's our new recurrence.
50:09
By adding this k parameter I've made
50:11
this recurrence on subproblems acyclic.
50:14
Unfortunately, I've increased the number of subproblems.
50:17
The number of subproblems now is v squared.
50:28
Technically, v times v minus 1.
50:30
Because I really-- actually, v squared.
50:32
Sorry.
50:34
I start at 0.
50:36
And what I care about, my goal, is delta sub v minus 1 of sv.
50:46
Because by Bellman-Ford analysis I
50:47
know that I only care about simple paths, paths of length
50:51
at most v minus 1.
50:52
I'm assuming here no negative weight cycles.
50:53
I should've said that earlier.
50:55
If you assume that, then this is what I care about.
50:58
So k ranges from 0 to v minus 1.
51:00
So there are v choices for k.
51:02
There are v choices for v. So the number of subproblems
51:04
is v squared.
51:05
How much time do I spend per subproblem?
51:07
Well, the same as before.
51:08
The indegree-- where did I write it?
51:09
Up here-- the indegree of that problem.
51:13
So what I'm really doing is summing
51:14
over all v of the indegree.
51:17
And then I multiply it by v. So the running time,
51:19
total running time is ve.
51:25
Sound familiar?
51:26
This is Bellman-Ford's algorithm again.
51:29
And this is actually where Bellman-Ford algorithm
51:32
came from is this view on dynamic programming.
51:35
So we're seeing yet another way to do Bellman-Ford.
51:38
It may seem familiar.
51:39
But in the next three lectures we're
51:41
going to see a whole bunch of problems
51:42
that can succumb to the same approach.
51:44
And that's super cool.
