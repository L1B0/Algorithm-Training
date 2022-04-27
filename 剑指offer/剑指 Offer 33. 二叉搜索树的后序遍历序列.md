```
bool myVerify(int* postorder, int l, int r){
    if(l >= r) return true;

    int ii=-1, i;
    for(i=l;i<r;i++){
        if(ii != -1 && postorder[i] < postorder[r])
        {
            return false;
        }
        if(postorder[i] > postorder[r] && ii == -1)
        {
            ii = i;
        }
    }
    if(ii == -1) return myVerify(postorder, l, r-1);

    return myVerify(postorder, l, ii-1) && myVerify(postorder, ii, r-1);
}
bool verifyPostorder(int* postorder, int postorderSize){
    bool result = myVerify(postorder, 0, postorderSize-1);
    return result;
}


```

