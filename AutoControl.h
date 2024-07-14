class SSModel {
    public:
    float samp_time = 0.5;

    float A[12][12];
    float B[12][3];
    float C[6][6];
    
    //let the state vector be of the form [x, y, z, Vx, Vy, Vz, roll, pitch, yaw, roll_rate, pit_rate, yaw_rate]
    float r[12];
    float x[12];
    float e[12];
    float e_past[13] = {0, 0, 0};
    float integral_error[3] = {0, 0, 0};
    float PID_matr[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    float command[3] = {0, 0, 0};

    //
    

    //Create a linearized state-space model [unfinished]
    void GenLSSM(){
        std::cout<<"Don't use this yet, jackass";
    }

    //Method to write reference into the class
    void AssignR(float reference[12]){
        for(int i = 0; i <= 11; i++){
            r[i] = reference[i];
        }
    }
    
    //Method to write state into the class
    void AssignX(float state[12]){
        for(int i = 0; i <= 11; i++){
            x[i] = state[i];
        }
    }
    
    //Calculate error between the reference and the current state trjectory
    void CalculateError(){
        for(int i = 0; i <= 11; i++){
            e[i] = r[i]-x[i];
        }
    }
    
    //PID Control to calculate velocity
    float CalculateVx(){
        command[0] = PID_matr[0][0]*( (e[3]-e_past[0])/samp_time) + PID_matr[0][1]*e[3] + PID_matr[0][2]*(e[3]*samp_time+integral_error[0]);
        e_past[0] = e[3];
        integral_error[0] += e[3]*samp_time;
        return command[0];
    }

    //PID control for roll
    float CalculateRoll(){
        command[1] = PID_matr[1][0]*( (e[6]-e_past[1])/samp_time) + PID_matr[1][1]*e[6] + PID_matr[1][2]*(e[6]*samp_time+integral_error[1]);
        e_past[1] = e[6];
        integral_error[1] += e[6]+samp_time;
        return command[1];
    }

    //PID control for pitch
    float CalculatePitch(){
        command[2] = PID_matr[2][0]*( (e[7]-e_past[2])/samp_time) + PID_matr[2][1]*e[7] + PID_matr[2][2]*(e[7]*samp_time+integral_error[2]);
        e_past[2] = e[7];
        integral_error[2] += e[7]*samp_time;
        return command[2];
        }
    
};