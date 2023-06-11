class SnapshotArray {
public:
    unordered_map<int,map<int,int>>mpp;
    int curr_snap=0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        mpp[index][curr_snap]=val;
    }
    
    int snap() {
        return curr_snap++;
    }
    
    int get(int index, int snap_id) {
        auto it=mpp[index].upper_bound(snap_id);
        return it==begin(mpp[index])?0:prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */