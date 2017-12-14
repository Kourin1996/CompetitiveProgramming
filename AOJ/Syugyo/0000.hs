
f :: (Int, Int) -> String
f (a,b) = show(a) ++ "x" ++ show(b) ++ "=" ++ show(a*b)

main = do
    let i = [ (x,y) | x<-[1..9], y<-[1..9] ]
        j = map f i
    putStr $ unlines $ j
